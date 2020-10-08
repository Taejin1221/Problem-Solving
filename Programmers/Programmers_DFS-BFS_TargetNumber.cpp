// Programmers_DFS-BFS_TargetNumber.cpp
// https://programmers.co.kr/learn/courses/30/lessons/43165
#include <vector>

using namespace std;

int ans;
void dfs( vector<int>& numbers, int curr, int idx ) {
	if ( numbers.size() == idx ) {
		if ( !curr )
			ans++;
	}
	else {
		dfs( numbers, curr - numbers[idx], idx + 1 );
		dfs( numbers, curr + numbers[idx], idx + 1 );
	}
}

int solution( vector<int> numbers, int target ) {
	dfs( numbers, target, 0 );

	return ans;
}