// Programmers76502.cpp
// https://programmers.co.kr/learn/courses/30/lessons/76502
// Programmers Monthly Programming Challenge 2 (April) Prob 2
#include <string>
#include <vector>

using namespace std;

int solution( string s ) {
	int answer = 0;

	int n = s.size();
	for ( int i = 0; i < n; i++ ) {
		bool isPossible = true;

		vector<char> stck;
		for ( int idx = i; idx < n; idx++ ) {
			if ( ( s[idx] == '(' ) || ( s[idx] == '{' ) || ( s[idx] == '[' ) )
				stck.push_back( s[idx] );
			else {
				if ( !stck.empty() ) {
					if ( (s[idx] == ')' && stck.back() == '(') ||
						(s[idx] == '}' && stck.back() == '{') ||
						(s[idx] == ']' && stck.back() == '[') )
						stck.pop_back();

				} else {
					isPossible = false;
					break;
				}
			}
		}

		if ( isPossible ) {
			for ( int idx = 0; idx < i; idx++ ) {
				if ( ( s[idx] == '(' ) || ( s[idx] == '{' ) || ( s[idx] == '[' ) )
					stck.push_back( s[idx] );
				else {
					if ( !stck.empty() ) {
						if ( (s[idx] == ')' && stck.back() == '(') ||
							(s[idx] == '}' && stck.back() == '{') ||
							(s[idx] == ']' && stck.back() == '[') )
							stck.pop_back();

					} else {
						isPossible = false;
						break;
					}
				}
			}
		}

		if ( !stck.empty() )
			isPossible = false;

		if ( isPossible )
			answer++;
	}

	return answer;
}