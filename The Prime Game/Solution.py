s = [0, 0, 1, 1, 2, 2, 3, 3, 4]
t = int(input())
for ti in range(t):
    n = int(input())
    a = [int(ai) for ai in input().strip().split(" ")]
    ans = 0
    for i in range(n):
        ans = ans^s[int(a[i]%len(s))]
    if(ans>0):
        print("Manasa")
    else:
        print("Sandy")
