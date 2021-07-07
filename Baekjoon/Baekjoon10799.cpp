// Baekjoon10799_IronBar.cpp
// https://www.acmicpc.net/problem/10799
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int main(void) {
	string bar;
	cin >> bar;

	int ans = 0;

	int curr = 0;
	for ( int i = 0; i < bar.size(); i++ ) {
		if ( bar[i] == '(' ) {
			if ( bar[i + 1] == ')' )
				ans += curr, i++;
			else
				curr++;
		}
		else
			curr--, ans++;
	}

	cout << ans << '\n';

	return 0;
}