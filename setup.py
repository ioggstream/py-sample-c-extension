#!/usr/bin/env python

from distutils.core import setup, Extension

setup(name='Simple Module',
      version='0.1',
      description='A simple Python Wrapper',
      author='Roberto Polli',
      author_email='rpolli@babel.it',
      url='http://www.babel.it',
      packages=['factorial'],
      ext_modules=[Extension("factorial/_factorial",
                              ["src/libfactorial.c",
                               "src/factorialfy.c",
                               ],
                              libraries=["m"])]
	)
