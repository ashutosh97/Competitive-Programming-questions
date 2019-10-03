def maxSubarraySum(a,  l):
	_max = -999999
	max_here = 0
	for i in range(l): 
		max_here = max_here + a[i]
		if (_max < max_here):
		 _max = max_here
		if (max_here < 0):
		 max_here = 0
	

	return _max


if __name__ == '__main__': 
	arr=[-2, -3, 4, -1, -2, 1, 5, -3]
	l=len(arr)
	m = maxSubarraySum(arr, l)
	print(m," is the max subarray sum")


