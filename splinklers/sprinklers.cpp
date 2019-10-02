/*
 * Copyright 2019 Ioana Voica
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream f("sprinklers.in", ios::in), g("sprinklers.out", ios::out);

	char stadium[128];
	f.getline(stadium, 128);

	int N, S;
	f >> N >> S;

	long long *x = new long long[N];
	long long *p = new long long[N];

	for (int i = 0; i < N; i++) {
		f >> x[i];
	}

	for (int i = 0; i < N; i++) {
		f >> p[i];
	}

	long long LCP = -1;
	int count = 0;

	if (x[0] - p[0] >= 0) {
		LCP = x[0];
		count++;

	} else if (x[0] + p[0] < x[1]) {
		LCP = x[0] + p[0];
		count++;
	}

	for (int i = 1; i < N -1; i++) {
		if (x[i] - p[i] > LCP && ((x[i] - p[i]) > x[i - 1])) {
			LCP = x[i];
			count++;

		} else if (x[i] + p[i] < x[i + 1]) {
			LCP = x[i] + p[i];
			count++;
		}
	}

	if ((x[N - 1] - p[N - 1] > LCP && (x[N - 1] - p[N - 1] > x[N - 2]))
	    || x[N - 1] + p[N - 1] <= S) {
		count++;
	}

	g << count;

	delete[] x;
	delete[] p;

	f.close();
	g.close();
	return 0;
}
