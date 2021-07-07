// Baekjoon11659_GetSegmentSum4.cpp
// https://www.acmicpc.net/problem/11659
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[100'000];
	int prefixSum[100'001] = { 0, };

	cin >> arr[0]; prefixSum[1] = arr[0];
	for ( int i = 1; i < n; i++ ) {
		cin >> arr[i];
		prefixSum[i + 1] = prefixSum[i] + arr[i];
	}

	while ( m-- ) {
		int s, e;
		cin >> s >> e;

		cout << prefixSum[e] - prefixSum[s - 1] << '\n';
	}

	return 0;
}