/*

Překlad:

gcc -Wall -std=c17 -pedantic demo.c -Wimplicit-fallthrough -o demo.so $(python3-config --cflags --ldflags) --shared -fPIC

(bez --embed pro python3-config; s --shared pro gcc; výstupní soubor (-o) má příponu .so)


python -c 'import demo; print(demo); print(demo.get_none()); print(demo.add(1))'

*/

#include <Python.h>

static PyObject *
demo_get_none(PyObject *module, PyObject *unused)
{
    return PyUnicode_FromFormat("-%T-", Py_None);
    Py_RETURN_NONE;  // ekvivalentní k: `return Py_NewRef(Py_None);`
    // ten kdo zavolal demo_get_none musí někdy zavolat Py_DECREF(Py_None);
}

// dú: `sum`, která sečte jakýkoli počet argumentů

static PyObject *
demo_add_py(PyObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    if (nargs != 3) {
        PyErr_Format(PyExc_TypeError, "demo.add expected 3 arguments (got %zd)", nargs);
        return NULL;
    }
    PyObject *intermediate = PyNumber_Add(args[0], args[1]);
    if (intermediate == NULL) {
        return NULL;
    } // jinak mám na starost referenci `intermediate`
    PyObject *result = PyNumber_Add(intermediate, args[2]);
    Py_DECREF(intermediate);  // zahodím referenci
    if (result == NULL) {
        return NULL;
    } // jinak mám na starost referenci `result`
    return result;  // referenci pošlu dál
}

static PyObject *
demo_add_c(PyObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    if (nargs != 2) {
        PyErr_Format(PyExc_TypeError, "demo.add expected 2 arguments (got %zd)", nargs);
        return NULL;
    }
    long a = PyLong_AsLong(args[0]);
    if (a == -1 && PyErr_Occurred()) {
        return NULL;
    }
    long b = PyLong_AsLong(args[1]);
    if (b == -1 && PyErr_Occurred()) {
        return NULL;
    }
    long result = a + b;
    return PyLong_FromLong(result);
}


static PyMethodDef demo_methods[] = {
    {"get_none", demo_get_none, METH_NOARGS, "Return None"},
    {"add_c", (PyCFunction)demo_add_c, METH_FASTCALL, "Add 2 numbers (C)"},
    {"add_py", (PyCFunction)demo_add_py, METH_FASTCALL, "Add 3 numbers (Py)"},
    {0},
};

PyDoc_STRVAR(
    mod_doc,
    "Modul kter\xc3\xbd um\xc3\xad skv\xc4\x9b"
    "l\xc3\xa9 v\xc4\x9b" "ci!"
);

static PyModuleDef demo_def = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "demo",
    .m_doc = mod_doc,
    .m_size = 0,
    .m_methods = demo_methods,
    .m_slots = NULL,
};

PyMODINIT_FUNC
PyInit_demo(void)
{
    /*
    PyErr_SetString(PyExc_ValueError, "jeste neumim import");
    return NULL;
    */
    return PyModuleDef_Init(&demo_def);
}
