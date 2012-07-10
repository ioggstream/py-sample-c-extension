/**
 *
 * Pollify.c
 * 
 * Evaluate a factorial in C
 * 
 */
#include <Python.h>
#include "factorial.h"

/**
 *  A long long int supports up to 10E+20, so 
 *   don't allow a factorial higher than that
 */
#define MAX_ALLOWED_VALUE (20)

/**
 * Exception if n>MAX_ALLOWED_VALUE
 */
static PyObject *FactorialOutOfBoundError;
static PyObject *DoYourHomeworkError;

/**
 * Python Prototypes
 * 
 * Exercise: write a wrapper around spyral
 */
static PyObject *
babel_factorial(PyObject *self, PyObject *args);

static PyObject *
babel_spyral(PyObject *self, PyObject *args);
/**
 * Method table
 *
 * We need prototypes or we should put this one at the end
 *  of the file
 */
static PyMethodDef BabelMethods[] = {
    {"factorial",  babel_factorial, METH_VARARGS,
     "Calculate a factorial of n between 0 and 21."},
    {"spyral",  babel_spyral, METH_VARARGS,
     "Calculate the arc-length of a symple spyral: ro=theta"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

/**
 * babel_factorial
 *
 * @params n
 * @return n!
 */

static PyObject *
babel_factorial(PyObject *self, PyObject *args)
{
	long long int ret = 1;
	// parse parameters
	long long int n;

	if (!PyArg_ParseTuple(args, "i", &n)) {
		/*
		 * NULL indicates an error
		 */
		return NULL;
	}

	if ( (n > MAX_ALLOWED_VALUE ) || (n < 0) ) {
		char buff[128];
                memset(&buff, 0, 128);
		snprintf(buff, 128, "Parameter out of range [0, %d ].", MAX_ALLOWED_VALUE);
		PyErr_SetString(FactorialOutOfBoundError, buff);
		return NULL;
	}

	// play the game
	ret = factorial(n);

	// eventually clean environment

	// return
	return PyLong_FromLong(ret);
}


/**
 * This is your homework
 */
static PyObject *
babel_spyral(PyObject *self, PyObject *args)
{
	PyErr_SetString(DoYourHomeworkError, "Do your homework!");
	return NULL;
}
/**
 * Python module initialization 
 *
 */
PyMODINIT_FUNC
init_factorial(void)
{
    PyObject *m;

    // Initialize all methods in BabelMethods table, or die
    m = Py_InitModule("_factorial", BabelMethods);
    if (m == NULL)
        return;

    {
    	// Define the new exception
    	FactorialOutOfBoundError = PyErr_NewException("_factorial.FactorialOutOfBoundError", NULL, NULL);
    	// Add it to the pystack: at least one copy of this object
    	//  should remain in memory
    	Py_INCREF(FactorialOutOfBoundError);
    	// add it to the module
    	PyModule_AddObject(m, "FactorialOutOfBoundError", FactorialOutOfBoundError);
    }
    {
    	// Define the new exception
    	DoYourHomeworkError = PyErr_NewException("_factorial.DoYourHomeworkError", NULL, NULL);
    	// Add it to the pystack: at least one copy of this object
    	//  should remain in memory
    	Py_INCREF(DoYourHomeworkError);
    	// add it to the module
    	PyModule_AddObject(m, "DoYourHomeworkError", DoYourHomeworkError);
    }




}


