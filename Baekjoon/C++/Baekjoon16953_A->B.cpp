// Baekjoon16953_A->B.cpp
// https://www.acmicpc.net/problem/16953

/* Review
 * Date
 01/09/2021

 * Solution
 { 값, 횟수 }를 노드로 갖고 BFS를 수행하면 된다. 주어진 연산들은 모두 숫자가 증가하는 방향이므로 curr 값이 B보다 커지면 절대 B가 될 수 없다.
 따라서 그런 경우를 제외하곤 연산들을 수행하여 큐에 집어넣고 최솟값을 찾는다.
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<long, long> pll;

int main(void) {
	int A, B;
	cin >> A >> B;

	queue<pll> q;
	q.push( { (long)A, 0l } );

	int ans = -1;
	while ( !q.empty() ) {
		pll curr = q.front(); q.pop();

		if ( curr.first == (long)B ) {
			ans = curr.second + 1;
			break;
		}

		if ( curr.first < B ) {
			q.push( { curr.first * 2, curr.second + 1 } );
			q.push( { curr.first * 10 + 1, curr.second + 1 } );
		}
	}

	cout << ans << '\n';

	return 0;
}
