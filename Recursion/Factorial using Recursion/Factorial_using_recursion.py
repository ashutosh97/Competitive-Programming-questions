def factorial(x):
	if x==1:
		return x;
	else:
	 return x*factorial(x-1);

t = int(input())

while t > 0:
	number = int(input())
	print(factorial(number));
	t -=1