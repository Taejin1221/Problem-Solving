// LeetCode1584_MinCostToConnectAllPoints.cpp
// https://leetcode.com/problems/min-cost-to-connect-all-points/
// LeetCode Weekly Contest 206
struct Node {
	int vertex, weight;
	Node( int v, int w ): vertex( v ), weight( w ) {}
	bool operator<( const Node& n2 ) const {
		return weight > n2.weight;
	}
};

class Solution {
public:
	int minCostConnectPoints( vector<vector<int>>& points ) {
		int ans = 0, size = points.size();

		vector<bool> visited ( size, false );
		priority_queue<Node> pq;
		pq.push( Node( 0, 0 ) );

		int visitedNum = size;
		while ( visitedNum ) {
			Node curr = pq.top(); pq.pop();
			if ( !visited[curr.vertex] ) {
				visited[curr.vertex] = true;
				visitedNum--;

				ans += curr.weight;

				for ( int i = 0; i < size; i++ ) {
					if ( !visited[i] ) {
						int nextWeight = abs( points[curr.vertex][0] - points[i][0] ) + abs( points[curr.vertex][1] - points[i][1] );
						pq.push( Node( i, nextWeight ) );
					}
				}
			}
		}

		return ans;
	}
};