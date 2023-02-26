// Programmers12938.cpp
// https://school.programmers.co.kr/learn/courses/30/lessons/12938
#include <vector>
#include <algorithm>

using namespace std;

void getBestSet(vector<int>& ans, int n, int s) {
	if (n != 0) {
		ans.push_back(s / n);
		getBestSet(ans, n - 1, s - (s / n));
	}
}

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s)
    	answer.push_back(-1);
    else {
	    getBestSet(answer, n, s);
	    sort(answer.begin(), answer.end());
    }

    return answer;
}