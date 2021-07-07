// Baekjoon01786_KMP.cpp
// https://www.acmicpc.net/problem/1786
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main(void) {
	char text[1000001], pattern[1000001];
	scanf("%[^\n]s", text); getchar();
	scanf("%[^\n]s", pattern); getchar();
	int n = strlen( text ), m = strlen( pattern );

	int fail[1000000];
	for ( int i = 1, j = 0; i < m; i++ ) {
		while ( j > 0 && pattern[j] != pattern[i] )
			j = fail[j - 1];

		if ( pattern[i] == pattern[j] )
			fail[i] = ++j;
	}

	vector<int> str;
	for ( int i = 0, j = 0; i < n; i++ ) {
		while ( j > 0 && text[i] != pattern[j] )
			j = fail[j - 1];

		if ( text[i] == pattern[j] )
			if ( j == m - 1 ) {
				str.push_back( i - m + 2 );
				j = fail[j];
			} else
				j++;
	}

	printf("%ld\n", str.size() );
	for ( auto i : str )
		printf("%d ", i );

	return 0;
}