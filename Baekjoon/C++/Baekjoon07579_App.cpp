// Baekjoon07579_App.cpp
// https://www.acmicpc.net/problem/7579

/* Review
 * Date
 01/09/2021

 * Idea
 전에 단계별로 풀어보기 설명란에 "발상의 전환이 필요한 냅색 문제"라는 설명을 보았던거 같아서 냅색 알고리즘으로 접근하였다.
 column은 앱의 인덱스로 해야한다는 것은 알았는데, byte를 row로 해버리면 최대가 1000만이라 MLE및 TLE가 뜨기 때문에 그건 안된다고 생각했다.
 그렇게 고민하다가 cost의 최댓값이 100이고 100개를 전부 비활성화하면 cost의 최댓값이 1만이라는 것을 계산하고 이걸 row로 설정해야겠다고 생각했다.
 이런 접근으로 냅색 알고리즘을 적용하였더니 쉽게 풀렸다.

 * Solution
 "최소의 비용으로 얻을 수 있는 최대 바이트를 계산"한다는 접근으로 Knapsack algorithm을 적용한다.
 1. DP Table을 채운다. dp[i][j] = (i만큼의 cost로 j index까지의 앱들 중 비활성화 했을 때 얻게 되는 가장 큰 byte의 갯수)
 2. currCost보다 j번째의 cost가 더 작다면 아래의 식을 적용한다. (기본적인 Knapsack)
 (min( dp[currCost][j - 1], dp[currCost - apps[j].cost][j - 1] + apps[j].byte )
 3. 만약 지금 구한 Byte가 원하는 Byte, 즉 m보다 크다면 currCost가 M byte를 확보하기 위한 최소 비용이다.
*/

#include <iostream>

#define MAX 10'001

using namespace std;

struct App {
	int cost, byte;
	App( ): cost( 0 ), byte( 0 ) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	App apps[100];
	for ( int i = 0; i < n; i++ )
		cin >> apps[i].byte;

	for ( int i = 0; i < n; i++ )
		cin >> apps[i].cost;

	int ans = 0;
	int dp[MAX][100] = { 0, };
	for ( int currCost = 1; currCost < MAX; currCost++ ) {
		int maxMemory = 0;
		if ( apps[0].cost <= currCost ) {
			dp[currCost][0] = apps[0].byte;
			maxMemory = apps[0].byte;
		}

		for ( int j = 1; j < n; j++ ) {
			if ( apps[j].cost <= currCost )
				dp[currCost][j] = max( dp[currCost][j - 1], dp[currCost - apps[j].cost][j - 1] + apps[j].byte );
			else
				dp[currCost][j] = dp[currCost][j - 1];

			maxMemory = max( maxMemory, dp[currCost][j] );
		}

		if ( maxMemory >= m ) {
			ans = currCost;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}