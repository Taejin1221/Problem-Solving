// Baekjoon04344_OverTheAverage.cpp
#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int time;

	scanf("%d", &time);
	for (int i = 0; i < time; i++) {
		int stdNum;
		double average = 0.0;
		vector<int> scores;

		scanf("%d", &stdNum);
		for (int i = 0; i < stdNum; i++) {
			int score;
			scanf("%d", &score);

			scores.push_back(score);
			average += score;
		}
		average /= stdNum;

		int goodStd = 0;
		for (int i = 0; i < stdNum; i++) {
			if ( scores[i] > average )
				goodStd++;
		}

		printf( "%.3f%\n", (double)goodStd / stdNum * 100 );
	}
}