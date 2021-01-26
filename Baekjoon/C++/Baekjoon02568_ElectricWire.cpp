// Baekjoon02568_ElectricWire.cpp
// https://www.acmicpc.net/problem/2568
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX_SIZE 1'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	pair<int, int> telephones[MAX_SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> telephones[i].first >> telephones[i].second;

	sort( telephones, telephones + n );

	int bTelephone[MAX_SIZE];
	for ( int i = 0; i < n; i++ )
		bTelephone[i] = telephones[i].second;

	int indexes[MAX_SIZE];
	vector<int> lisTable;
	for ( int i = 0; i < n; i++ ) {
		int idx = lower_bound( lisTable.begin(), lisTable.end(), bTelephone[i] ) - lisTable.begin();
		if ( idx == lisTable.size() )
			lisTable.push_back( bTelephone[i] );
		else
			lisTable[idx] = bTelephone[i];
		indexes[i] = idx;
	}

	int lisSize = lisTable.size();

	int findIdx = lisSize - 1;
	vector<int> lisIndexes( lisSize );
	for ( int i = n - 1; i >= 0; i-- )
		if ( indexes[i] == findIdx )
			lisIndexes[findIdx--] = i;

	cout << n - lisSize << '\n';

	int lisIdx = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( i == lisIndexes[lisIdx] )
			lisIdx++;
		else
			cout << telephones[i].first << '\n';
	}

	return 0;
}