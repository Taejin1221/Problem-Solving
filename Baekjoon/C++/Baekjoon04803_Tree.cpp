// Baekjoon04803_Tree.cpp
// https://www.acmicpc.net/problem/4803

/*
Review
 * date 01/06/2021

 * 문제 경로
 주안킴이 틀렸다고 찾아온 문제라 나도 풀어봤다. Cycle Detection은 역시 Disjoint Set이라 Disjoint Set으로 풀었다.

 * Solution
 Gold IV 문제라 Disjoint Set 단순 적용으로 가볍게 풀 수 있을줄 알았지만 생각보다 오래걸렸다.
 a, b가 Cycle이라면 a나 b가 들어가는 Graph는 Tree가 될 수 없기 때문에 cycle이라는 set에 넣어주었다. set을 쓴 이유는 같은 노드가 중복되서 들어올 수 있기 때문이다.
 그리고 모든 노드들의 Root를 검사하여 Unique한 숫자들을 찾았다. 이것들이 Tree의 갯수이기 때문이다. 하지만 그 전에 Cycle이 생긴 Tree는 Tree가 아니라 이것들을 걸러줘야한다.
 따라서 check를 하기 전에 이전에 cycle set에 넣어준 노드들의 root를 찾아서 graph에 표시해 주었고, 만약 현재 check하려는 노드가 graph면 ans를 증가시켜 주지 않았다.

 * idea
 뭔가 대단한 방법이 있을 것 같아 고민하느라 시간을 좀 썼다. 하지만 좋은 방법이 생각나지 않고 n이 500이라 그냥 set이랑 테이블 여러개 만들어서 해결하였다.

*/

#include <iostream>
#include <set>

using namespace std;

int parent[501];

int FindRoot( int target );
void Union( int aRoot, int bRoot );
void Print( int time, int tree );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int time = 1;
	while ( !(n == 0 && m == 0) ) {
		for ( int i = 1; i <= n; i++)
			parent[i] = i;
		
		set<int> cycle;
		for ( int i = 0; i < m; i++ ) {
			int a, b;
			cin >> a >> b;

			int aRoot = FindRoot( a ), bRoot = FindRoot( b );
			if ( aRoot == bRoot )
				cycle.insert( aRoot );
			else
				Union( aRoot, bRoot );
		}

		bool graphRoot[501] = { false, };
		for ( set<int>::iterator iter = cycle.begin(); iter != cycle.end(); ++iter )
			graphRoot[FindRoot( *iter )] = true;

		int ans = 0;
		bool check[501] = { false, };
		for ( int i = 1; i <= n; i++ ) {
			int iRoot = FindRoot( i );
			if ( !graphRoot[iRoot] && !check[iRoot] ) {
				ans++;
				check[iRoot] = true;
			}
		}

		Print( time, ans );

		cin >> n >> m;
		time++;
	}

	return 0;
}

int FindRoot( int target ) {
	return ( parent[target] == target ? target : FindRoot( parent[target] ) );
}

void Union( int aRoot, int bRoot ) {
	if ( aRoot < bRoot )
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}

void Print( int time, int tree ) {
	cout << "Case " << time << ": ";
	if ( tree == 0 )
		cout << "No trees.";
	else if ( tree == 1 )
		cout << "There is one tree.";
	else
		cout << "A forest of " << tree << " trees.";
	cout << '\n';
}