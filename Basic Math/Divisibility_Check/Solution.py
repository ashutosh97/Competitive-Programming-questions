lista = list(map(int,input().split()));
have = False
for i in range(0,len(lista)):
	for j in range(0,len(lista)):
		if lista[i]%lista[j] == 0 and i!=j:
			have = True
if have == True:
	print(1)
else:
	print(0)