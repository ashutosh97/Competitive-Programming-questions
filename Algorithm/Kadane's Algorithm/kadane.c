#include <stdio.h>
#include <limits.h>

int maxSubarraySum(int a[], int l) {
	int max = INT_MIN, max_here = 0;

	for (int i = 0; i < l; i++) {
		max_here = max_here + a[i];
		if (max < max_here) max = max_here;
		if (max_here < 0) max_here = 0;
	}

	return max;
}

// int maxSubarraySum(int a[], int l) {
// 	int max = a[0], max_here = a[0];

// 	for (int i = 0; i < l; i++) {
// 		if (max_here > 0) max_here += a[i];
// 		else max_here = a[i];
// 		if (max_here > max) max = max_here;
// 	}

// 	return max;
// }

int main(int argc, char *argv[]) {
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int l = sizeof(arr) / sizeof(int);

	int m = maxSubarraySum(arr, l);

	printf("%d is the max subarray sum\n", m);

	return 0;
}