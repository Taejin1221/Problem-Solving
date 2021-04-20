// Codeforces690_A.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int arr[300];
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		int size = 0, startIdx = 0, endIdx = n - 1;
		while ( size < n ) {
			cout << arr[startIdx++] << ' ';
			size++;

			if ( size < n ) {
				cout << arr[endIdx--] << ' ';
				size++;
			}
		}
		cout << '\n';
	}

	return 0;
}