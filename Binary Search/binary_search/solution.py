def binarySearch(arr,ele):
	l=0
	r=len(arr)-1
	while(l<=r):
		m=(l+r)//2
		if(arr[m]==ele):
			return True
		else:
			if(arr[m]<ele):
				l=m+1
			else:
				r=m-1
	return False

if __name__ == '__main__':
	#sorted array
	arr=[1,2,3,4,5]

	if(binarySearch(arr,1)):
		print("Exists")
	else:
		print("Doesnt exist")
