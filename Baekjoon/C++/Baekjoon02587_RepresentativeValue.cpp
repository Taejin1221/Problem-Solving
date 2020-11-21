// Baekjoon02587_RepresentativeValue.cpp
// https://www.acmicpc.net/problem/2587
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int sum = 0;

	int arr[5];
	for ( int i = 0; i < 5; i++ ) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort( arr, arr + 5 );
	cout << sum / 5 << '\n';
	cout << arr[2] << '\n';

	return 0;
}