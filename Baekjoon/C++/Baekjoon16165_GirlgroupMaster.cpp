// Baekjoon16165_GirlgroupMaster.cpp
// https://www.acmicpc.net/problem/16165
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> memberData;
	map<string, vector<string>> teamData;
	for ( int i = 0; i < n; i++ ) {
		string team;
		cin >> team;

		int memberNumber;
		cin >> memberNumber;

		for ( int j = 0; j < memberNumber; j++ ) {
			string member;
			cin >> member;

			if ( teamData.find( team ) == teamData.end() )
				teamData[team] = vector<string> ();
			teamData[team].push_back( member );

			memberData[member] = team;
		}

		sort( teamData[team].begin(), teamData[team].end() );
	}

	for ( int i = 0; i < m; i++ ) {
		string name;
		cin >> name;

		int quiz;
		cin >> quiz;

		if ( quiz == 0 ) {
			for ( string& name : teamData[name] )
				cout << name << '\n';
		} else {
			cout << memberData[name] << '\n';
		}
	}

	return 0;
}