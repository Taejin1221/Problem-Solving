// Baekjoon25206.cpp
// https://www.acmicpc.net/problem/25206
#include <cstdio>
#include <iostream>

#include <string>

using namespace std;

double getScore(string grade) {
	if (grade == "A+")
		return 4.5;
	else if (grade == "A0")
		return 4.0;
	else if (grade == "B+")
		return 3.5;
	else if (grade == "B0")
		return 3.0;
	else if (grade == "C+")
		return 2.5;
	else if (grade == "C0")
		return 2.0;
	else if (grade == "D+")
		return 1.5;
	else if (grade == "D0")
		return 1.0;
	else if (grade == "F")
		return 0.0;
	else
		return 0.0;
}

int main(void) {
	double sumScore = 0.0, sumTime = 0.0;
	for (int i = 0; i < 20; i++) {
		string subject, grade;
		double time;

		cin >> subject >> time >> grade;
		if (grade != "P")
			sumTime += time, sumScore += getScore(grade) * time;
	}

	printf("%.6lf\n", sumScore / sumTime);

	return 0;
}
