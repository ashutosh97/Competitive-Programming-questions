#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> a, int l) {
	int max = INT_MIN, max_here = 0;

	for (int i = 0; i < l; i++) {
		max_here = max_here + a[i];
		if (max < max_here) max = max_here;
		if (max_here < 0) max_here = 0;
	}

	return max;
}


int main() {
	vector<int> arr({-2, -3, 4, -1, -2, 1, 5, -3});
	int l = arr.size();

	int m = maxSubarraySum(arr, l);

	cout<<m<<" is the max subarray sum\n";

	return 0;
}
