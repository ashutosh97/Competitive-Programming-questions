# Python3 program to check if two strings are anagram of each other

def are_anagram(s1, s2):
    """ Check if two strings are anagram of each other.

    Apply XOR to all characters of both strings. If the final value is 0, then
    there is an even occurence of all characters, ie the two strings are
    anagram. Otherwise, there are not anagram.

    Args:
        s1 (str): First string
        s2 (str): Second string

    Returns:
        bool: True if the two strings are anagram of each other, otherwise False
    """
    # Two strings with different sizes can not be anagram of each other
    if len(s1) != len(s2):
        return False

    # Apply XOR to all characters of both strings
    xor_value = 0
    for c1, c2 in zip(s1, s2):
        xor_value = xor_value ^ ord(c1)
        xor_value = xor_value ^ ord(c2)

    return not bool(xor_value)

def main():
    """ Driver code """
    s1 = 'listen'
    s2 = 'silent'
    s3 = 'hacktoberfest'
    print('{} / {} -> {}'.format(s1, s2, are_anagram(s1, s2)))
    print('{} / {} -> {}'.format(s1, s3, are_anagram(s1, s3)))
    print('{} / {} -> {}'.format(s2, s3, are_anagram(s2, s3)))

if __name__=='__main__':
    main()
