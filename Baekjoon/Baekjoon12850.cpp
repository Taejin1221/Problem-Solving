// Baekjoon12850.cpp
// https://www.acmicpc.net/problem/12850
#include <iostream>

#include <vector>

#define MOD 1'000'000'007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;

vvl basicMatrix{
	{ 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 1, 0, 1 },
	{ 0, 0, 0, 1, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 1, 0 }
};

vvl pow(int y) {
	if (y == 1)
		return vvl(basicMatrix.begin(), basicMatrix.end());
	else {
		vvl halfResult = pow(y / 2);
		vvl result(8, vector<ll>(8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					ll temp = halfResult[i][k] * halfResult[k][j] % MOD;
					result[i][j] = (result[i][j] + temp) % MOD;
				}
			}
		}

		if (y % 2) {
			vvl tempResult(result);
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					result[i][j] = 0;
					for (int k = 0; k < 8; k++) {
						ll temp = tempResult[i][k] * basicMatrix[k][j] % MOD;
						result[i][j] = (result[i][j] + temp) % MOD;
					}
				}
			}
		}

		return result;
	}

}

int main(void) {
	int n;
	cin >> n;

	vvl result = pow(n);
	cout << result[0][0] << '\n';

	return 0;
}