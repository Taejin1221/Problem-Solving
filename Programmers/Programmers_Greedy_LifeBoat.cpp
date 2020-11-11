// Programmers_Greedy_LifeBoat.cpp
// https://programmers.co.kr/learn/courses/30/lessons/42885
#include <vector>
#include <algorithm>

using namespace std;

int solution( vector<int> people, int limit ) {
	int answer = 0;

	sort( people.begin(), people.end(), greater<int>() );

	int light = people.size() - 1;
	for ( int i = 0; i <= light; i++ ) {
		int boat = limit - people[i];
		if ( people[i] + people[light] <= limit )
			light--;
		answer++;
	}

	return answer;
}