// Baekjoon01931_MeetingRoom.cpp
// https://www.acmicpc.net/problem/1931
#include <algorithm>
#include <iostream>

using namespace std;

bool compare( pair<int, int> opr1, pair<int, int> opr2 ) {
	if ( opr1.second > opr2.second )
		return false;
	else if ( opr1.second < opr2.second )
		return true;
	else {
		if ( opr1.first >= opr2.first )
			return false;
		else
			return true;
	}
}

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );

	pair<int, int> meetings[100000];
	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> meetings[i].first >> meetings[i].second;

	sort( meetings, meetings + n, compare );

	int maxMeetingNum = 1;
	int endTime = meetings[0].second;
	for ( int i = 1; i < n; i++ ) {
		if ( meetings[i].first >= endTime ) {
			maxMeetingNum++;
			endTime = meetings[i].second;
		}
	}

	cout << maxMeetingNum << '\n';

	return 0;
}