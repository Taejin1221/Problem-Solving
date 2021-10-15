// Baekjoon23242.cpp
// https://www.acmicpc.net/problem/23242
#include <cstdio>
#include <limits>

#define MAX_SIZE 4000
#define INF numeric_limits<double>::max()
#define SQUARE(x) ((x) * (x))

using namespace std;

typedef long long ll;

double min(double a, double b) {
	return (a < b) ? a : b;
}

int main(void) {
	int B; // Bucket의 수
	scanf("%d", &B);

	int n; // frequency의 수
	scanf("%d", &n);

	int arr[4'000];

	ll sum[4'001] = { 0, }, squareSum[4'001] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum[i + 1] = sum[i] + arr[i];
		squareSum[i + 1] = squareSum[i] + SQUARE(arr[i]);
	}

	double ans = INF, dp[31][MAX_SIZE];
	for (int i = 0; i < n; i++) {
		dp[1][i] = squareSum[i + 1];
		dp[1][i] -= (double)SQUARE(sum[i + 1]) / (i + 1);
	}
	ans = min(ans, dp[1][n - 1]);

	for (int i = 2; i <= B; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
			for (int k = i - 2; k < j; k++) {
				double mse = squareSum[j + 1] - squareSum[k + 1];
				mse -= (double)SQUARE((sum[j + 1] - sum[k + 1])) / (j - (k + 1) + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + mse);
			}
		}
		ans = min(ans, dp[i][n - 1]); // 최대 B개의 bucket을 사용하여 만들 수 있으므로 bucket마다 값 저장
	}

	printf("%.4lf\n", ans);

	return 0;
}