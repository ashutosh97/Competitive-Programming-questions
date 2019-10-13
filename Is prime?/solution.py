import math
def isPrime(number):
    if number < 2 or (number % 2 == 0 and number > 2):
        return False
    for num in range(2, int(math.sqrt(number)) + 1):
        if not number % num:
            return False
    return True
