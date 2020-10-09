s=input()
upperCase=[]
lowerCase=[]
even=[]
odd=[]
for i in s:
    if i >= 'A' and i<= 'Z':
        upperCase.append(i)
    elif i >='a' and i<= 'z':
        lowerCase.append(i)
    elif int(i)%2 == 0:
        even.append(i)
    elif int(i)%2 != 0:
        odd.append(i)

upperCase.sort()
lowerCase.sort()
even.sort()
odd.sort()

print("".join(lowerCase+upperCase+odd+even))
