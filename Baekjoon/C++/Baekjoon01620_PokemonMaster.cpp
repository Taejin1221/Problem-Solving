// Baekjoon01620_PokemonMaster.cpp
// https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	string nameTable[100'001];
	map<string, int> idxTable;

	for ( int i = 1; i <= n; i++ ) {
		string temp;
		cin >> temp;

		idxTable[temp] = i;
		nameTable[i] = temp;
	}

	string opr;
	for ( int i = 0; i < m; i++ ) {
		cin >> opr;

		if ( '0' <= opr[0] && opr[0] <= '9' )
			cout << nameTable[stoi( opr )] << '\n';
		else
			cout << idxTable[opr] << '\n';
	}

	return 0;
}