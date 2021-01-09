// Baekjoon02638_Cheese.cpp
// https://www.acmicpc.net/problem/2638

/* Review
 * Date
 01/09/2021

 * 잡담
 BFS 공부할 때 다른 치즈를 풀었었다. 그땐 가볍게 풀었었는데 지금은 조금 오래걸렸다. 하지만 그때보다 코드는 더 나은듯(물론 내 생각).
 처음엔 Graph Traversal을 안쓰고 푸려고 했다. 하지만 내부 외부 빈공간을 분리하는데 결국엔 필요해서 결국엔 BFS를 사용하였다.

 * Solution
 기본적인 Solution은 다음과 같다.
 1. 지금(현재 시간) 녹는 것들은 currTime 값을 할당하고, 지금 녹지 않는 것들은 nextTime을 할당한다.
 (즉, 그 칸에 있는 치즈가 녹는 시간을 labeling)
 2. currTime을 할당할 때는 주변에 currTime보다 작은 값들이 2개 이상일 때이다.
 (즉, 이전에 녹았던 치즈가 주변에 2개 있을 때)
 3. time은 증가하며 반복한다.
 4. 치즈가 주어질 때 1로 주어진다. 그렇기때문에 currTime은 0으로 시작해야하는게 맞지만, 1로 할당했다. 따라서 출력할 때 1을 빼준다.

 하지만 이렇게하면 내부 빈공간도 녹이는데 영향을 주는 빈공간으로 치고 녹이면 안되는 치즈도 녹인다. 따라서 BFS를 0, 0점에서 시작해서 외부, 내부 빈공간을 분리해준다.
 내부 빈공간은 -2라는 특정한 상수를 이용하였다. 따라서 위의 2번 과정에서 빈공간인지 아닌지를 판단하는 조건도 넣어준다.

 * 끝으로...
 이렇게 solved.ac class 4의 Gold 문제를 모두 풀었다. 얼른 Silver도 풀고 class 5도 정복하러 가야겠다.
*/

#include <iostream>
#include <queue>

#define INSIDE -2

using namespace std;

typedef pair<int, int> pii;

const int rowChanges[4] = { -1, 0, 1, 0 }, colChanges[4] = { 0, 1, 0, -1 };

int n, m;
int cheeses[100][100];
bool visited[100][100];

int GetEmpty( int row, int col );
void DivisionInAndOut( int value ); // value보다 작거나 같은 값들을 value로 할당

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int restCheese = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			cin >> cheeses[i][j];
			if ( cheeses[i][j] )
				restCheese++;
			else
				cheeses[i][j] = INSIDE;
		}
	}

	int currTime = 1, nextTime = 2;
	while ( restCheese > 0 ) {
		// BFS로 외부 내부 분리
		DivisionInAndOut( currTime - 1 );

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				if ( cheeses[i][j] == currTime ) {
					int empty = GetEmpty( i, j );
					
					if ( empty >= 2 )
						restCheese--;
					else
						cheeses[i][j] = nextTime;
				}
			}
		}

		currTime = nextTime;
		nextTime++;
	}

	cout << currTime - 1 << '\n';

	return 0;
}

int GetEmpty( int row, int col ) {
	int count = 0;
	for ( int i = 0; i < 4; i++ ) {
		int newRow = row + rowChanges[i], newCol = col + colChanges[i];
		if ( ( 0 <= newRow && newRow < n ) && ( 0 <= newCol && newCol < m ) ) {
			if ( cheeses[newRow][newCol] != INSIDE && cheeses[newRow][newCol] < cheeses[row][col] )
				count++;
		}
	}

	return count;
}

void DivisionInAndOut( int value ) {
	queue<pii > q;
	bool visited[100][100] = { true, };

	cheeses[0][0] = value;
	q.push( { 0, 0 } );
	while ( !q.empty() ) {
		pii curr = q.front(); q.pop();

		for ( int i = 0; i < 4; i++ ) {
			int newRow = curr.first + rowChanges[i], newCol = curr.second + colChanges[i];
			if ( ( 0 <= newRow && newRow < n ) && ( 0 <= newCol && newCol < m ) ) {
				if ( !visited[newRow][newCol] ) {
					visited[newRow][newCol] = true;
					if ( cheeses[newRow][newCol] <= value ) {
						cheeses[newRow][newCol] = value;
						q.push( { newRow, newCol } );
					}
				}
			}
		}
	}
}