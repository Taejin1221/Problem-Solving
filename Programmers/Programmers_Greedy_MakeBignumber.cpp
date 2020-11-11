// Programmers_Greedy_MakeBignumber.cpp
// https://programmers.co.kr/learn/courses/30/lessons/42883
#include <string>

using namespace std;

string solution( string number, int k ) {
	string answer = number;
	for ( int i = 0; i < k; i++ ) {
		int idx = 0;
		while ( idx < answer.size() && answer[idx] >= answer[idx + 1] )
			idx++;

		if ( idx == answer.size() )
			answer.erase( answer.size() - 1, 1 );
		else
			answer.erase( idx, 1 );
	}

	return answer;
}