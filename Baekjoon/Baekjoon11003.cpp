// Baekjoon11003_FindMinvalue.cpp
// https://www.acmicpc.net/problem/11003
#include <iostream>
#include <deque>

#define MAX_SIZE 5'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l;
	cin >> n >> l;

	int arr[MAX_SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	deque<int> dq;
	for ( int i = 0; i < n; i++ ) {
		while ( !dq.empty() && arr[dq.back()] >= arr[i] )
			dq.pop_back();

		dq.push_back( i );
		while ( !dq.empty() && ( i - dq.front() ) >= l )
			dq.pop_front();

		cout << arr[dq.front()] << ' ';
	}
	cout << '\n';

	return 0;
}
