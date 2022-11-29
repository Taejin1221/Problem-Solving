// BOJ_13229.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int arr[100'000], sum[100'001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i + 1] = sum[i] + arr[i];
	}

	int m;
	cin >> m;
	while (m--) {
		int start, end;
		cin >> start >> end;

		cout << sum[end + 1] - sum[start] << '\n';
	}

	return 0;
}