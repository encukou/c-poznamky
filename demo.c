/* Spousteni:

$ gcc -Wall -std=c17 -pedantic demo.c -Wimplicit-fallthrough -o demo $(python3-config --cflags --libs --embed)
$ ./demo

*/

#include <Python.h>

int main() {
    Py_Initialize();
    PyObject *globals = PyDict_New();
    if (globals == NULL) {
        printf("Nastala chyba pri vytvareni slovniku!\n");
        PyErr_Print();
        Py_Finalize();
        return 1;
    }
    PyObject *vysledek = PyRun_String("a = 1.0 + 2\nprint(a)\ndel a", Py_file_input, globals, globals);
    if (vysledek == NULL) {
        printf("Nastala chyba pri provadeni programu!\n");
        PyErr_Print();
        Py_DECREF(globals);
        Py_Finalize();
        return 1;
    }
    Py_DECREF(vysledek);

    PyObject *py_a = PyMapping_GetItemString(globals, "a");
    if (py_a == NULL) {
        printf("Nastala chyba pri ziskavani promenne!\n");
        PyErr_Print();
        Py_DECREF(globals);
        Py_Finalize();
        return 1;
    }
    long int c_a = PyLong_AsLong(py_a);
    if (c_a == -1 && PyErr_Occurred()) {
        printf("Nastala chyba pri prevodu na C long int!\n");
        PyErr_Print();
        Py_DECREF(py_a);
        Py_DECREF(globals);
        Py_Finalize();
        return 1;
    }

    printf("1+2 = %ld\n", c_a);

    Py_DECREF(py_a);
    Py_DECREF(globals);
    Py_Finalize();
    return 0;
}
