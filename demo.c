/* Spousteni:

$ gcc -Wall -std=c17 -pedantic demo.c -Wimplicit-fallthrough -o demo $(python3-config --cflags --ldflags --embed)
$ ./demo

*/

#include <Python.h>


int main() {
    int result = 1;
    Py_Initialize();
    PyObject *py_a = NULL;
    PyObject *globals = PyDict_New();
    if (globals == NULL) {
        printf("Nastala chyba pri vytvareni slovniku!\n");
        goto finally;
    }
    PyObject *vysledek = PyRun_String("a = 1.0 + 2\nprint(a)\ndel a", Py_file_input, globals, globals);
    if (vysledek == NULL) {
        printf("Nastala chyba pri provadeni programu!\n");
        goto finally;
    }
    Py_CLEAR(vysledek);

    py_a = PyMapping_GetItemString(globals, "a");
    if (py_a == NULL) {
        printf("Nastala chyba pri ziskavani promenne!\n");
        goto finally;
    }
    long int c_a = PyLong_AsLong(py_a);
    if (c_a == -1 && PyErr_Occurred()) {
        printf("Nastala chyba pri prevodu na C long int!\n");
        goto finally;
    }

    printf("1+2 = %ld\n", c_a);
    result = 0;

finally:
    if (PyErr_Occurred()) {
        PyErr_Print();
    }
    Py_CLEAR(py_a);
    Py_CLEAR(globals);
    Py_Finalize();
    return result;
}
