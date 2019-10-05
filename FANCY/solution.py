# cook your dish here
x=int(input())
p=0
flag=0
while(p<x):
    s=str(input())
    s=s.split(" ")
    for i in range(len(s)):
        if(s[i]=='not'):
            print("Real Fancy")
            flag=1
            break
    if(flag==0):
        print("regularly fancy")
    flag=0
    p=p+1