import nose

class TestOne:
	def setUp(self):
	    print "setup"
	
	def tearDown(self):
	    print "teardown"
	
	
	def dont_do(self):
	    print "don't do it"
	
	def test_do1(self):
	    print "do 1"
	def test_do2(self):
	    print "do 2"
