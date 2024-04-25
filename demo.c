// gcc -Wall --std=c17 -pedantic demo.c -Wimplicit-fallthrough $(python3-config --cflags --ldflags) --shared -fPIC -o demo.so

//  bez --embed pro python3-config

#include <Python.h>

PyModuleDef demo_def = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "demo",
    .m_doc = NULL,
    .m_size = 0,
    .m_methods = NULL,
    .m_slots = NULL,
};

PyMODINIT_FUNC
PyInit_demo(void) {
    // PyErr_SetString(PyExc_ValueError, "jeste neumim import");
    return PyModuleDef_Init(&demo_def);
}