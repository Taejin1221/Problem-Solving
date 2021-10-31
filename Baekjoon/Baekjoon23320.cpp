// Hongik_A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[100];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int x, y;
	cin >> x >> y;

	int ans1 = n * x / 100;
	int ans2 = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] >= y)
			ans2++;

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}