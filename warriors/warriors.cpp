/*
 * Copyright 2019 Ioana Voica
 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	freopen("warriors.in", "r", stdin);
	freopen("warriors.out", "w", stdout);

	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);

	if (K == 1) {
		printf("%d", N);
		return 0;
	}

	if (K > log2(N)) {
		int answer = log2(N) + 1;
		printf("%d", answer);
		return 0;
	}

	int mid, right, left;

	right = N;
	left = 0;

	while (right > left + 1) {
		mid = left + (right - left) / 2;

		long long binomial = 0;
		float cnk = 1;

		for(int i = 1; i <= K && binomial <= N; i++) {
			float aux = mid - i + 1;
			cnk *= aux / i;
			binomial += cnk;
		}

		if (binomial >= N) {
			right = mid;

		} else {
			left = mid;
		}
	}

	left++;
	printf("%d", left);
	return 0;
}

