#!/usr/bin/env python
from unittest import TestCase, main

class MyTestClass(TestCase):
	def setUp(self):
		print "setup"
	
	def tearDown(self):
		print "teardown"
	
	def test_do1(self):
		print "do 1"
	def do2(self):
		print "do 2"
	def test_do3(self):
		print "do 3"
	

if __name__== '__main__':
	exit(main())
