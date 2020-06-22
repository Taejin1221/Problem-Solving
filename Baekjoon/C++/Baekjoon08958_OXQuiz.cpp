// Baekjoon08958_OXQuiz.cpp
#include <iostream>

using namespace std;

int main(void) {
	string testcase;
	int time;

	cin >> time;
	for (int i = 0; i < time; i++) {
		int score = 0, prevScore = 0;

		cin >> testcase;
		for (int idx = 0; idx < testcase.length(); idx++) {
			if ( testcase[idx] == 'O' )
				score += ++prevScore;
			else
				prevScore = 0;
		}
		cout << score << endl;
	}

	return 0;
}