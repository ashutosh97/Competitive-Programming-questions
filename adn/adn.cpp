/*
 * Copyright 2019 Ioana Voica
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char strings[4][100];
char result[400];
bool dp[101][101][101][101];

int check_adn(int N) {
	char concat[400];
	for (int i = 0; i < 4; i++) {
		strcat(concat, strings[i]);
	}
	if (!strcmp(concat, result)) {
		return 1;
	}

	int lengths[4];
	for (int i = 0; i < 4; i++) {
		if (i >= N) {
			lengths[i] = 0;
		} else {
			lengths[i] = strlen(strings[i]);
		}
	}

	for (int i = 0; i <= lengths[0]; i++) {
		for (int j = 0; j <= lengths[1]; j++) {
			for (int k = 0; k <= lengths[2]; k++) {
				for (int p = 0; p <= lengths[3]; p++) {
					int index = i + j + k + p - 1;
					bool aux;
					aux = ((i == 0 && j == 0 && k == 0 && p == 0)

					       || (i > 0 && strings[0][i - 1] == result[index]
					           && dp[i - 1][j][k][p])

					       || (j > 0 && strings[1][j - 1] == result[index]
					           && dp[i][j - 1][k][p])

					       || (k > 0 && strings[2][k - 1] == result[index]
					           && dp[i][j][k - 1][p])

					       || (p > 0 && strings[3][p - 1] == result[index]
					           && dp[i][j][k][p - 1]));

					if (aux) {
						dp[i][j][k][p] = 1;
					} else {
						dp[i][j][k][p] = 0;
					}
				}
			}
		}
	}

	return dp[lengths[0]][lengths[1]][lengths[2]][lengths[3]];
}

int main() {
	freopen("adn.in", "r", stdin);
	freopen("adn.out", "w", stdout);

	int T, N;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;

		int lengths_sum = 0;

		for (int j = 0; j < N; j++) {
			cin >> strings[j];
			lengths_sum += strlen(strings[j]);
		}

		cin >> result;
		if (lengths_sum != strlen(result)) {
			cout << 0 << '\n';

		} else {
			cout << check_adn(N) << '\n';
		}
	}

	return 0;
}

