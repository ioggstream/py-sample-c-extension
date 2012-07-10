import unittest
import nose


def import_test():
    from factorial import factorial
    assert factorial
    pass

def import_missing_test():
    from factorial import factorial
    try:
        factorial.fac 
        assert False, "I accepted an unexisting method"
    except AttributeError:
        pass

def factorial_boundary_test():
    from factorial import factorial
    assert  factorial(0) == 1
    assert  factorial(1) == 1
    assert  factorial(20) == 20 * factorial(19)

def factorial_oob_test():
    from factorial import factorial, FactorialOutOfBoundError
    for i in [-1, -10, 100, 70, 21]:
        try:
            factorial(i)
            assert False, "I accepted values out of bound [0,20]"
        except FactorialOutOfBoundError:
            pass

def factorial_invalid_test():
    from factorial import factorial
    for i in ["a", "&", "9999999", None]:
        try:
            factorial(i)
            assert False, "I accepted values out of bound [0,20]"
        except TypeError:
            pass


def factorial_test():
    from factorial import factorial
    assert  factorial(3) == 6
    assert  factorial(4) == 24
    assert  factorial(5) == 120
    
def spyral_test():
    from factorial import factorial, spyral, DoYourHomeworkError

    try:
        spyral(1)
        assert False
    except DoYourHomeworkError:
        pass

@nose.SkipTest
def factorial_find_boundary_test():
    from factorial import factorial
    n = 1
    (ret,prev) = (1,0)
    while True:
        prev = ret
        n = n + 1
        ret = factorial(n)        
        assert ret > prev, "Integer size limit reached: n: %d" % n
