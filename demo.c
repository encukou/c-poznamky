// gcc -Wall --std=c17 -pedantic demo.c -Wimplicit-fallthrough $(python3-config --cflags --ldflags) --shared -fPIC -o demo.so

//  bez --embed pro python3-config

#include <Python.h>

static PyObject *
demo_get_none(PyObject *self, PyObject *unused)
{
    Py_RETURN_NONE;
    // tohle zvedne pocet referenci a vraci pythoni objekt:
    // return Py_NewRef(Py_None);
}

static PyObject *
demo_add(PyObject *self, PyObject *const *args, Py_ssize_t nargs)
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
    {"add", (PyCFunction)demo_add, METH_FASTCALL, "Add 2 numbers"}, 
    {"get_none", demo_get_none, METH_NOARGS, "Return None"}, 
    {0},
};

PyDoc_STRVAR(
    mod_doc,
    "Modul, ktery umi skvele veci"
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
PyInit_demo(void) {
    // PyErr_SetString(PyExc_ValueError, "jeste neumim import");
    return PyModuleDef_Init(&demo_def);
}