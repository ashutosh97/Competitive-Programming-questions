#!/bin/python3

import math
import os
import random
import re
import sys

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    numbers = list("0123456789")
    lower_case = list("abcdefghijklmnopqrstuvwxyz")
    upper_case = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    special_characters = list("!@#$%^&*()-+")
    count = 0
    length = len(password)
    flagn = 0
    flagl = 0
    flagu = 0
    flags = 0
    for i in password:
        if i in numbers:
            flagn = 1
    for i in password:
        if i in lower_case:
            flagl = 1
    for i in password:
        if i in upper_case:
            flagu = 1
    for i in special_characters:
        if i in password:
            flags = 1
    if flagn == 0:
        count+=1
    if flagu == 0:
        count+=1
    if flagl == 0:
        count+=1
    if flags == 0:
        count+=1    
    
    check = length + count
    if check < 6:
        count = count + (6 - (length + count))
    return count  
    
if __name__ == '__main__':

    n = int(input())

    password = input()

    answer = minimumNumber(n, password)

    print(answer)
