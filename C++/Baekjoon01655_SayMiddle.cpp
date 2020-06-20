// Baekjoon01655_SayMiddle.cpp
// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue> /* priority_queue */

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> smalls;
	priority_queue<int, vector<int>, greater<int>> bigs;

	int time; cin >> time;

	int middle, newNum;
	cin >> middle;
	cout << middle << '\n';
	time--;
	
	while ( time-- ) {
		cin >> newNum;
		if ( newNum < middle ) {
			smalls.push( newNum );
			if ( smalls.size() > bigs.size() ) {
				bigs.push( middle );
				middle = smalls.top(); smalls.pop();
			}
		} else {
			bigs.push( newNum );
			if ( bigs.size() - smalls.size() > 1 ) {
				smalls.push( middle );
				middle = bigs.top(); bigs.pop();
			}
		}

		cout << middle << '\n';
	}

	return 0;
}