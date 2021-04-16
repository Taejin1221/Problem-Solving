// Programmers76501.cpp
// https://programmers.co.kr/learn/courses/30/lessons/76501
// Programmers Monthly Programming Challenge 2 (April) Prob 1
#include <vector>

using namespace std;

int solution( vector<int> absolutes, vector<bool> signs ) {
	int ans = 0;

	for ( int i = 0; i < absolutes.size(); i++ ) {
		if ( signs[i] )
			ans += absolutes[i];
		else
			ans -= absolutes[i];
	}

	return ans;
}