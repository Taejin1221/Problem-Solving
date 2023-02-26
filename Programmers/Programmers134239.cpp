// Programmers134239.cpp
// https://school.programmers.co.kr/learn/courses/30/lessons/134239?language=cpp
#include <vector>

using namespace std;

using ll = long long;

double abs(ll a) {
	return (double)(a < 0) ? -a : a;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<ll> arr;
    arr.push_back(k);
    while (k != 1) {
    	if (k % 2)
    		k = k * 3 + 1;
    	else
    		k /= 2;
    	arr.push_back(k);
    }

    for (vector<int>& range : ranges) {
    	int start = range[0], end = arr.size() - 1 + range[1];
    	if (start > end)
    		answer.push_back(-1.0);
    	else {
    		double result  = 0.0;
    		for (int i = start + 1; i <= end; i++) {
    			result += min(arr[i - 1], arr[i]);
    			result += abs(arr[i - 1] - arr[i]) / 2.0;
    		}

    		answer.push_back(result);
    	}
    }

    return answer;
}