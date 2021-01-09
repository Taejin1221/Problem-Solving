// Baekjoon15666_NandM12.cpp
// https://www.acmicpc.net/problem/15666

/* Review
 * Date
 01/09/2021

 * Solution
 중복을 제거한 뒤 정렬한 다음 백트래킹을 수행하였다. 중복 제거와 정렬을 set을 이용하여 한번에 수행하였다.
 비내림차순이어야하기 때문에 index는 지속적으로 증가하는 방향으로 진행한다.
*/

#include <iostream>

#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> ans;

void dfs( int idx, vector<int>& curr ) {
	if ( curr.size() == m )
		ans.push_back( curr );
	else {
		for ( int i = idx; i < arr.size(); i++ ) {
			curr.push_back( arr[i] );
			dfs( i, curr );
			curr.pop_back( );
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	set<int> s;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		s.insert( temp );
	}

	for ( set<int>::iterator iter = s.begin(); iter != s.end(); ++iter )
		arr.push_back( *iter );

	vector<int> curr;
	dfs( 0, curr );

	for ( vector<int>& row : ans ) {
		for ( int& value : row )
			cout << value << ' ';
		cout << '\n';
	}

	return 0;
}