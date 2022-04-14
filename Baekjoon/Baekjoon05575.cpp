// Baekjoon05575.cpp
// https://www.acmicpc.net/problem/5575
#include <iostream>

using namespace std;

struct Time {
	int hour, minute, second;
	Time(): hour(0), minute(0), second(0) { }
	Time(int h, int m, int s): hour(h), minute(m), second(s) { }

	Time operator-(const Time& t2) const {
		Time result;

		int carry = 0;
		result.second = second - t2.second;
		if (result.second < 0) {
			result.second += 60;
			carry = 1;
		}

		result.minute = minute - t2.minute - carry;
		carry = 0;
		if (result.minute < 0) {
			result.minute += 60;
			carry = 1;
		}

		result.hour = hour - t2.hour - carry;

		return result;
	}
};

int main(){
	for (int i = 0; i < 3; i++) {
		Time start, end;
		cin >> start.hour >> start.minute >> start.second >> end.hour >> end.minute >> end.second;

		Time interval = end - start;
		cout << interval.hour << ' ' << interval.minute << ' ' << interval.second << '\n';
	}

	return 0;
}
