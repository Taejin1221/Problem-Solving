// Baekjoon01963_PrimePath.cpp
// https://www.acmicpc.net/problem/1963
#include <iostream>

#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int decimal_digits[4] = { 1'000, 100, 10, 1 };
bool isPrime[10'001];

int myAtoi( string num ) {
	int result = 0;
	for ( int i = 3; i >= 0; i-- )
		result += (num[i] - '0') * decimal_digits[i];

	return result;
}

void Solve( ) {
	string start, target;
	cin >> start >> target;

	queue<pair<string, int>> q;
	bool visited[10'001] = { false, };

	int ans = 0;
	bool canChange = false;
	q.push( { start, 0 } );
	visited[myAtoi(start)] = true;
	while ( !q.empty() ) {
		pair<string, int> curr = q.front(); q.pop();

		if ( curr.first == target ) {
			canChange = true;
			ans = curr.second;
			break;
		}

		for ( int i = 0; i <= 3; i++ ) {
			string temp = curr.first;
			for ( char digit = '0'; digit <= '9'; digit++ ) {
				temp[i] = digit;

				int tempNum = myAtoi( temp );
				if ( 1'000 <= tempNum && isPrime[tempNum] && !visited[tempNum] ) {
					visited[tempNum] = true;
					q.push( { temp, curr.second + 1 } );
				}
			}

		}
	}

	if ( canChange )
		cout << ans;
	else
		cout << "Impossible";
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill( isPrime, isPrime + 10'001, true );

	isPrime[1] = false;
	for ( int i = 2; i <= 100; i++ ) {
		if ( isPrime[i] ) {
			for ( int j = i * i; j <= 10'000; j += i )
				isPrime[j] = false;
		}
	}

	int t;
	cin >> t;
	while ( t-- )
		Solve();

	return 0;
}