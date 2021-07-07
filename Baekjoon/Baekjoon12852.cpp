// Baekjoon12852_Make1II.cpp
// https://www.acmicpc.net/problem/12852
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int visited[1'000'001] = { 0, };
	int oper[1'000'001];

	queue<int> q;
	q.push( n );

	while ( !q.empty() ) {
		int curr = q.front(); q.pop();

		if ( curr == 1 )
			break;

		if ( curr % 3 == 0 && !visited[curr / 3] ) {
			visited[curr / 3] = visited[curr] + 1;
			oper[curr / 3] = 1;
			q.push( curr / 3 );
		}

		if ( curr % 2 == 0 && !visited[curr / 2] ) {
			visited[curr / 2] = visited[curr] + 1;
			oper[curr / 2] = 2;
			q.push( curr / 2 );
		}

		if ( !visited[curr - 1] ) {
			visited[curr - 1] = visited[curr] + 1;
			oper[curr - 1] = 3;
			q.push( curr - 1 );
		}
	}

	cout << visited[1] << '\n';

	int curr = 1;
	vector<int> ans;

	ans.push_back( curr );
	while ( curr != n ) {
		int temp = curr;
		if ( oper[curr] == 1 )
			curr *= 3;
		else if ( oper[curr] == 2 )
			curr *= 2;
		else if ( oper[curr] == 3 )
			curr += 1;

		ans.push_back( curr );
	}

	for ( int i = ans.size() - 1; i >= 0; i-- )
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
