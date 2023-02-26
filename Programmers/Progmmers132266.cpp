// Progmmers132266.cpp
// https://school.programmers.co.kr/learn/courses/30/lessons/132266
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<int> adjList[100'001];
    for (vector<int>& road : roads) {
    	adjList[road[0]].push_back(road[1]);
    	adjList[road[1]].push_back(road[0]);
    }

    bool visited[100'001];

    for (int& source : sources) {
    	queue<pii> q;

    	fill(visited + 1, visited + n + 1, false);

    	q.push({ source, 0 });
    	visited[source] = true;

    	int result = -1;
    	while (!q.empty()) {
    		pii curr = q.front(); q.pop();
    		if (curr.first == destination) {
    			result = curr.second;
    			break;
    		}

    		for (int& adj : adjList[curr.first]) {
    			if (!visited[adj]) {
    				visited[adj] = true;
    				q.push({ adj, curr.second + 1 });
    			}
    		}
    	}

    	answer.push_back(result);
    }

    return answer;
}