def lilysHomework(arr):
    m = {}
    for i in range(len(arr)):
        m[arr[i]] = i
    sorted_arr = sorted(arr)
    res = 0
    for i in range(len(arr)):
        if(arr[i] != sorted_arr[i]):
            res += 1
            x = m[sorted_arr[i]]
            m[ arr[i] ] = m[ sorted_arr[i]]
            arr[i],arr[x] = sorted_arr[i],arr[i]
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = min(lilysHomework(list(arr)), lilysHomework(list(arr[::-1])))

    fptr.write(str(result) + '\n')

    fptr.close()
