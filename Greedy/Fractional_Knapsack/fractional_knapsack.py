def isort_(a):
	'''
	Algorithm  : Insertion Sort (Modified a/c to data)
	Sort Order : Descending
	Utility    : Rearrange data for pick_greedy()
	'''
	for i in range(1,len(a)):
		temp = a[i]
		val = a[i][0]
		j = i-1
		while j>=0 and val>a[j][0]:
			a[j+1] = a[j]
			j-=1
		a[j+1] = temp

def pick_greedy(a,m):
	# Rearrange
	isort_(a)

	# Greedy Approach : Selecting the Max Pi/Wi
	i = 0
	while m>0:
		m-=a[i][1][0]
		i+=1
	
	'''
	Reader may Ignore all Complications in next Code Segment.. 
	Done only for better view at the Results.
	'''
	# Display Results 
	print(f"\nNo. of Items Picked : : {i}")
	psum = 0
	for x in a[:i-1]:
		print(f"   {x[1][0]:2.0f} Item(s) from {x[1]}")
		psum += x[1][1]
	last_i = a[i-1][1][0] + m
	psum += last_i*a[i-1][0]
	print(f"   {last_i:2.0f} Item(s) from {a[i-1][1]}")
	print(f"Max Possible Price :: {psum}")


# Input Cases 
t = int(input("\nTest Cases : "))
for i in range(1,t+1):

	print(f"\n------------ CASE #{i}  -------------")
	n = int(input("\nTotal Items  : "))
	m = int(input("Max Capacity : "))
	wi = [int(i) for i in input("\nWeights : ").split(" ")]
	pi = [int(i) for i in input("Prices  : ").split(" ")]
	
	ppw = [(round(i[1]/i[0],2),i) for i in zip(wi,pi)]
	# ppw = [float p/w, tuple (w, p) ... ]

	# Display Inputs
	print(f"\nData Table  :{[j for i,j in ppw]}")
	print(f"Price/Weight : {[round(i,2) for i,j in ppw]}")
	# Perform Greedy Algorithm
	pick_greedy(ppw,m)
