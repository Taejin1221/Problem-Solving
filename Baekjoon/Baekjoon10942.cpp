// Baekjoon10942_Palindrome?.cpp
// https://www.acmicpc.net/problem/10942

/* Review
 * Date
 01/11/2021

 * Idea
 n이 2,000이고 쿼리가 m, 시간제한이 0.5이다. 따라서 O(n^2)이 가능하고 쿼리는 O(1)이어야한다.
 따라서 특정 범위가 Palindrome인지 n^2 테이블에 저장한 뒤 쿼리를 O(1)에 찾는 방법을 생각했다.
 테이블에 저장한다 -> DP, palindrome인지 아닌지는 n/2 solution이 있지만 이러면 O(n^3)이 필요하다.
 따라서 n^2에 끝내려면 palindrome 판단을 한번에 해야한다. 이 경우는 palindrome의 재귀적 구조를 찾아 해결했다.
 만약 처음과 끝이 같고, 그 사이가 palindrome이면 그 범위는 palindrome이다.

 * Solution
 dp[i][j] = index i부터 index j가 palindrome인가(true) 아닌가(false)?
 1. i == j면 수열의 길이가 1이니 palindrome이다.
 2. i부터 j까지의 수열이 palindrome이려면 arr[i] == arr[j]이면서 그 사이의 범위가 palindrome이면 된다.
 ( if ( arr[i] == arr[j] ) dp[i][j] = dp[i + 1][j - 1] );
*/
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[2'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	bool dp[2'000][2'000] = { false, };
	for ( int i = 0; i < n; i++ ) {
		dp[i][i] = true;
		if ( i + 1 < n && arr[i] == arr[i + 1] )
			dp[i][i + 1] = true;
	}

	for ( int interval = 2; interval < n; interval++ ) {
		for ( int i = 0; i < n - interval; i++ ) {
			int j = i + interval;
			if ( arr[i] == arr[j] ) {
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}

	int q;
	cin >> q;

	while ( q-- ) {
		int s, e;
		cin >> s >> e;

		cout << dp[--s][--e] << '\n';
	}

	return 0;
}