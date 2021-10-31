// Hongik_C.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int arr[2'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	pair<int, int> ans = { 0, 0 };
	for (int  i = 1; i < n; i++) {
		if (arr[i] != arr[0])
			ans.first++, ans.second += arr[i] - arr[0];
	}

	cout << ans.second << ' ' << ans.first << '\n';

	return 0;
}