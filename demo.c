/*

Překlad:

gcc -Wall -std=c17 -pedantic demo.c -Wimplicit-fallthrough -o demo.so $(python3-config --cflags --ldflags) --shared -fPIC

(bez --embed pro python3-config; s --shared pro gcc; výstupní soubor (-o) má příponu .so)


python -c 'import demo; print(demo)'

*/

#include <Python.h>

PyModuleDef demo_def = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "demo",
    .m_doc = NULL, // todo
    .m_size = 0,
    .m_methods = NULL,
    .m_slots = NULL,
};

PyMODINIT_FUNC
PyInit_demo(void) {
    /*
    PyErr_SetString(PyExc_ValueError, "jeste neumim import");
    return NULL;
    */
    return PyModuleDef_Init(&demo_def);
}

