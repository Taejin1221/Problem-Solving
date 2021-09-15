// Baekjoon02110_InstallRouter.cpp
// https://www.acmicpc.net/problem/2110
#include <algorithm> /* sort() */
#include <iostream>

using namespace std;

int n, c;
int homes[200'000];

int Router(int dis) {
	int sum = 1, prevIdx = 0;
	for (int currIdx = 1; currIdx < n; currIdx++) {
		if (dis <= homes[currIdx] - homes[prevIdx]) {
			prevIdx = currIdx;
			sum++;
		}
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> c;
	
	for (int i = 0; i < n; i++)
		cin >> homes[i];
	sort(homes, homes + n);

	int ans = 0;
	int left = 1, right = homes[n - 1] - homes[0];
	while (left <= right) {
		int mid = (left + right) / 2;

		int result = Router(mid);
		if (c <= result) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
			right = mid - 1;
	}

	cout << ans << '\n';

	return 0;
}