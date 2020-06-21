// Baekjoon02529_Inequality.cpp
// https://www.acmicpc.net/problem/2529
#include <iostream>

using namespace std;

int n;
char inequal[9]; 
char bigNum[11], smallNum[11];
bool visited_big[10], visited_small[10];

bool isValid( char* nums, bool* visited, int idx, char num );
bool DFS_big( int idx );
bool DFS_small( int idx );

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> inequal[i];

	DFS_big( 0 );
	DFS_small( 0 );

	cout << bigNum << '\n';
	cout << smallNum << '\n';

	return 0;
}

bool isValid( char* nums, bool* visited, int idx, char num ) {
	if ( idx == 0 )
		return true;
	
	if ( !visited[num - 48] ) {
		if ( inequal[idx - 1] == '<' ) {
			if ( nums[idx - 1] < num )
				return true;
			else
				return false;
		} else {
			if ( nums[idx - 1] > num )
				return true;
			else
				return false;
		}
	} else
		return false;
}

bool DFS_big( int idx ) {
	if ( idx == n + 1 ) {
		return true;
	} else {
		for ( char i = '9'; i >= '0'; i-- ) {
			if ( isValid( bigNum, visited_big, idx, i ) ) {
				visited_big[i - 48] = true;
				bigNum[idx] = i;
				if ( DFS_big( idx + 1 ) )
					return true;
				else
					visited_big[i - 48] = false;
			}
		}

		return false;
	}
}

bool DFS_small( int idx ) {
	if ( idx == n + 1 ) {
		return true;
	} else {
		for ( char i = '0'; i <= '9'; i++ ) {
			if ( isValid( smallNum, visited_small, idx, i ) ) {
				visited_small[i - 48] = true;
				smallNum[idx] = i;
				if ( DFS_small( idx + 1 ) )
					return true;
				else
					visited_small[i - 48] = false;
			}
		}

		return false;
	}
}