def get_longest_sorted_sequence(words):
    count = 1
    total_letters = 0
    current = 0
    increasing_sum = 0
    is_sequence = True

    if len(words) == 0:
        return 0
    else:
        current = len(words[0])

    for i in range (1, len(words)):
        next = len(words[i])
        if current == next-1:
            print(current)
            # in sequence
            count += 1
            current = len(words[i])
            print(current)
        else:
            current = len(words[i])

    return count


# test cases
print ('Actual  :' + str(get_longest_sorted_sequence(['a', 'is', 'ape', 'in'])))
print ()


print ('Actual  :' + str(get_longest_sorted_sequence(['apple', 'in', 'has', 'wed', 'code', 'rocks', 'bee'])))
print ()


print ('Actual  :' + str(get_longest_sorted_sequence(['apple'])))
print ()

print ('Actual  :' + str(get_longest_sorted_sequence([])))
print ()
