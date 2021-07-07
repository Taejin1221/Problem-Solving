// Baekjoon15663_NandM9.cpp
// https://www.acmicpc.net/problem/15663

/* Review
 * Date
 01/09/2021

 * Solution
 효율적인 방법은 아니지만 생각이 나지 않아 m개를 선택한 다음 현재까지 만든 수열에 중복이 있는지 일일히 탐색했다. 기껏해야 m이 8개라 가능했던 것 같다.
 Backtracking은 숫자를 정렬한 뒤 중복을 선택하지 않도록 visited를 두고 index는 매번 0부터 시작한다.
*/

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
vector<vector<int>> ans;

void dfs( vector<int>& curr, bool visited[] ) {
	if ( curr.size() == m ) {
		bool isDuplication = false;

		for ( vector<int>& row : ans ) {
			bool tempDuplication = true;
			for ( int i = 0; i < m; i++ ) {
				if ( curr[i] != row[i] ) {
					tempDuplication = false;
					break;
				}
			}

			if ( tempDuplication ) {
				isDuplication = true;
				break;
			}
		}

		if ( !isDuplication )
			ans.push_back( curr );
	} else {
		for ( int i = 0; i < n; i++ ) {
			if ( !visited[i] ) {
				visited[i] = true;
				curr.push_back( arr[i] );
				dfs( curr, visited );
				curr.pop_back( );
				visited[i] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	vector<int> curr;
	bool visited[8] = { false, };
	dfs( curr, visited );

	for ( vector<int>& row : ans ) {
		for ( int& value : row )
			cout << value << ' ';
		cout << '\n';
	}

	return 0;
}
