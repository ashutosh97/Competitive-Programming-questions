#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(int *n, vector<int> *stones) {
    cin >> *n;
    vector<int> v(*n);
    for (int i = 0; i < *n; ++i) {
        cin >> v[i];
        int temp = v[i];
        int j = 0;
        int f = 1;
        for (int l = 2; l * l <= temp; ++l) {
            if (temp % l == 0) {
                if (j == l) {
                    ++f;
                    if (f == 2) {
                        v[i] /= j * j;
                        f = 0;
                    }
                } else {
                    f = 1;
                    j = l;
                }
                temp /= l;
                --l;
            }
        }
        if (temp == j) {
            ++f;
            if (f == 2) {
                v[i] /= j * j;
            }
        }
    }
    sort(v.begin(), v.end());
    stones->push_back(1);
    for (int i = 1; i < *n; ++i) {
        if (v[i] == v[i - 1]) {
            ++stones->at(stones->size() - 1);
        } else {
            stones->push_back(1);
        }
    }
}

int necklace(size_t n, const std::vector<int> &stones, int mod) {
    std::vector<long long> data_first(n);
    std::vector<long long> data_second(n);
    std::vector<std::vector<long long>> c(n + 2, std::vector<long long>(n + 2));
    std::vector<long long> fact(n + 2);
    c[0][0] = 1;
    fact[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        c[i][0] = 1;
        for (int j = 1; j <= n + 1; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int count = stones[0] - 1;
    data_second[stones[0] - 1] = fact[stones[0]];
    for (int stone = 1; stone < stones.size(); ++stone) {
        if (stones[stone] != 0) {
            std::vector<long long> temp_first = std::move(data_first);
            std::vector<long long> temp_second = std::move(data_second);
            data_first = std::vector<long long>(n);
            data_second = std::vector<long long>(n);
            for (int i = 0; i < n; ++i) {
                if (temp_first[i] != 0) {
                    for (int l = 1; l <= stones[stone]; ++l) {
                        for (int j = 0; j <= std::min(i, l); ++j) {
                            long long temp1 = 0;
                            if (count >= i) {
                                temp1 = (c[count - i][l - j] * c[i][j]) % mod;
                                temp1 = (temp1 * c[stones[stone] - 1][l - 1]) % mod;
                                temp1 = (temp1 * fact[stones[stone]]) % mod;
                                temp1 = (temp1 * temp_first[i]) % mod;
                            }
                            long long temp2 = 0;
                            if (count + 1 >= i) {
                                temp2 =
                                        (c[count - i + 1][l - j] * c[i][j]) % mod;
                                temp2 = (temp2 * c[stones[stone] - 1][l - 1]) % mod;
                                temp2 = (temp2 * fact[stones[stone]]) % mod;
                                temp2 = (temp2 * temp_first[i]) % mod;
                            }
                            temp2 = (temp2 * 2) % mod;
                            temp2 = (temp2 - temp1) % mod;
                            if (temp2 < 0) {
                                temp2 += mod;
                            }
                            data_first[i - j + stones[stone] - l] =
                                    (data_first[i - j + stones[stone] - l] +
                                     temp2) % mod;
                            if (l - j >= 2) {
                                temp1 =
                                        (c[count - i][l - j - 2] * c[i][j]) % mod;
                                temp1 = (temp1 * c[stones[stone] - 1][l - 1]) % mod;
                                temp1 = (temp1 * fact[stones[stone]]) % mod;
                                temp1 = (temp1 * temp_first[i]) % mod;
                                data_second[i - j + stones[stone] - l] =
                                        (data_second[i - j + stones[stone] - l] +
                                         temp1) % mod;
                            }
                        }
                    }
                }
                if (temp_second[i] != 0) {
                    for (int l = 1; l <= stones[stone]; ++l) {
                        for (int j = 0; j <= std::min(i, l); ++j) {
                            long long temp1 = 0;
                            if (count >= i) {
                                temp1 = (c[count - i][l - j] * c[i][j]) % mod;
                                temp1 = (temp1 * c[stones[stone] - 1][l - 1]) % mod;
                                temp1 = (temp1 * fact[stones[stone]]) % mod;
                                temp1 = (temp1 * temp_second[i]) % mod;
                                data_second[i - j + stones[stone] - l] =
                                        (data_second[i - j + stones[stone] - l] +
                                         temp1) % mod;
                            }
                            long long temp2 = 0;
                            if (count + 1 >= i) {
                                temp2 =
                                        (c[count - i + 1][l - j] * c[i][j]) % mod;
                                temp2 = (temp2 * c[stones[stone] - 1][l - 1]) % mod;
                                temp2 = (temp2 * fact[stones[stone]]) % mod;
                                temp2 = (temp2 * temp_second[i]) % mod;
                            }
                            temp2 = (temp2 * 2) % mod;
                            temp1 = (temp1 * 2) % mod;
                            temp2 = (temp2 - temp1) % mod;
                            if (temp2 < 0) {
                                temp2 += mod;
                            }
                            data_first[i - j + stones[stone] - l] =
                                    (data_first[i - j + stones[stone] - l] +
                                     temp2) % mod;
                            if (l - j >= 2) {
                                temp1 =
                                        (c[count - i][l - j - 2] * c[i][j]) % mod;
                                temp1 = (temp1 * c[stones[stone] - 1][l - 1]) % mod;
                                temp1 = (temp1 * fact[stones[stone]]) % mod;
                                temp1 = (temp1 * temp_second[i]) % mod;
                                data_second[i - j + stones[stone] - l] =
                                        (data_second[i - j + stones[stone] - l] +
                                         temp1) % mod;
                            }
                        }
                    }
                }
            }
            count += stones[stone];
        }
    }
    return (int) ((data_first[0] + data_second[0]) % mod);
}

int rek(std::vector<int> *v, int last, int first) {
    int res = 0;
    int k = 0;
    for (int &a : *v) {
        if (a != -1) {
            ++k;
            if (a != last) {
                int temp = a;
                a = -1;
                if (first == -1) {
                    res += rek(v, temp, temp);
                } else {
                    res += rek(v, temp, first);
                }
                a = temp;
            }
        }
    }
    if (k == 0) {
        if (first != last) {
            return 1;
        }
        return 0;
    }
    return res;
}

bool test() {
    int n = rand() % 10 + 1;
    int k = rand() % 10 + 1;
    std::vector<int> stones(k);
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % k;
        ++stones[v[i]];
    }
    std::sort(stones.rbegin(), stones.rend());
    if (rek(&v, -1, -1) != necklace(n, stones, 1000000007)) {
        std::cout << n << " " << k << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
        std::cout << rek(&v, -1, -1) << " ";
        std::cout << necklace(n, stones, 1000000007) << std::endl;
        return false;
    }
    return true;
}

void tests() {
    srand(16);
    int c = 0;
    int count = 1000;
    while (c++ < count && test());
}

int main() {
    int n;
    std::vector<int> stones;
    input(&n, &stones);
    std::cout << necklace((size_t) n, stones, 1000000007) << std::endl;
    fclose(stdin);
    fclose(stdout);
//    tests();
    return 0;
}
