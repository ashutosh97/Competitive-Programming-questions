L = [int(input('enter element ')) for I in range(int(input('enter size of list ')))]
print(L)

def bubble_sort(L):
    for I in range(n-1):
        for J in range(n-1):
            if L[J]>L[J+1]:
                L[J],L[J+1]=L[J+1],L[J]
    return L

def insertion_sort(L):
    for I in range(1,n):
        x = L[I]
        pos =I
        while pos>0 and x<L[pos-1]:
            L[pos] = L[pos-1]
            pos = pos - 1
        L[pos] = x
    return L

def selection_sort(L):
    for I in range(n):
        min_idx = i
        for J in range(i+1,n):
            if L[min_idx]>L[J]:
                min_idx = j
        L[I],L[min_idx]=L[min_idx],L[I]
    return L

print('bubble sort : B')
print('insertion sort : I')
print('selection sort : S')

choice = input('enter your choice (B/I/S)')

if choice=='B':
    print(bubble_sort(L))
elif choice=='I':
    print(insertion_sort(L))
elif choice=='S':
    print(selection_sort(L))
    
    
