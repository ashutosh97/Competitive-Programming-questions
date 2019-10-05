#!/usr/bin/python
from math import *

def euclid_algo(x, y, verbose=True):
    if x < y: # We want x >= y
        return euclid_algo(y, x, verbose)
        print()
    while y != 0:
        if verbose: print('%s = %s * %s + %s' % (x, floor(x/y), y, x % y))
        (x, y) = (y, x % y)
        if verbose: print('gcd is %s' % x) 
        return x
euclid_algo(150, 304)
euclid_algo(1000, 10)
euclid_algo(150, 9)
