// Baekjoon24390.cpp
// https://www.acmicpc.net/problem/24390
#include <iostream>

#include <queue>
#include <tuple>
#include <string>

using namespace std;

using tiib = tuple<int, int, bool>;

const int plusTime[3] = { 10, 60, 600 };

int main(void) {
	string time;
	cin >> time;

	int target = 0;
	target += ((time[0] - '0') * 10 + (time[1] - '0')) * 60;
	target += (time[3] - '0') * 10 + (time[4] -'0');

	// { time, num, isStart }
	queue<tiib> q;
	bool visited[2][5000] = { { false, }, };

	q.push(make_tuple(0, 0, false));
	visited[0][0] = true;

	int ans = 0;
	while (!q.empty()) {
		tiib curr = q.front(); q.pop();
		if (get<0>(curr) == target && get<2>(curr)) {
			ans = get<1>(curr);
			break;
		}

		for (int i = 0; i < 3; i++) {
			int nextTime = get<0>(curr) + plusTime[i];
			if (nextTime <= 3600 && !visited[get<2>(curr)][nextTime]) {
				visited[get<2>(curr)][nextTime] = true;
				q.push(make_tuple(nextTime, get<1>(curr) + 1, get<2>(curr)));
			}
		}

		int nextTime = get<0>(curr) + (get<0>(curr) == 0 ? 30 : 0);
		if (nextTime <= 3600 && !visited[1][nextTime]) {
			visited[1][nextTime] = true;
			q.push(make_tuple(nextTime, get<1>(curr) + 1, true));
		}
	}

	cout << ans << '\n';

	return 0;
}