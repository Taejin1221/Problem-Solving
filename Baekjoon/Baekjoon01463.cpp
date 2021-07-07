// Baekjoon01463_Make1.cpp
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <climits>

#define MAX_ARR_SIZE 1000001

using namespace std;

int minFunc( int arr[] ) {
	if ( arr[0] <= arr[1] && arr[0] <= arr[2] )
		return arr[0];
	else if ( arr[1] <= arr[0] && arr[1] <= arr[2] )
		return arr[1];
	else
		return arr[2];
}

int main(void) {
	int table[MAX_ARR_SIZE] = { 0, 0, };

	int n;
	cin >> n;

	int tempArr[3];
	for ( int i = 2; i <= n; i++ ) {
		tempArr[0] = (i % 2) ? INT_MAX : table[i / 2];
		tempArr[1] = (i % 3) ? INT_MAX : table[i / 3];
		tempArr[2] = table[i - 1];

		table[i] = minFunc( tempArr ) + 1;
	}

	cout << table[n] << '\n';

	return 0;
}
