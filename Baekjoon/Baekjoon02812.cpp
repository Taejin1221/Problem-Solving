// Baekjoon02812_MakeBigger.cpp
// https://www.acmicpc.net/problem/2812
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	char number[500'000];
	cin >> number;

	vector<char> stck;
	for ( int i = 0; i < n; i++ ) {
		while ( !stck.empty() && stck.back() < number[i] && k > 0 ) {
			stck.pop_back();
			k--;
		}
		stck.push_back( number[i] );
	}

	while ( k > 0 ) {
		stck.pop_back();
		k--;
	}

	for ( int i = 0; i < stck.size(); i++ )
		cout << stck[i];
	cout << '\n';

	return 0;
}