def func(n):

    while n!=1:
        if n % 2 == 0:
            n //= 2
            list.append(n)
        else:
            n = n * 3 + 1
            list.append(n)



n = int(input())
list = []
list.append(n)
func(n)
for i in list:
    print(i, end=" ")
