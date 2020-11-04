// LeetCode0684_RedundantConnection.cpp
// https://leetcode.com/problems/redundant-connection/
// method 1 : DFS
class Solution {
private:
	bool hasCycle( int me, int mom, vector<int>& removeEdge, vector<vector<int>>& adjList, vector<bool>& visited ) {
		visited[me] = true;

		for ( int& son : adjList[me] ) {
			if ( son != mom ) {
				if ( (removeEdge[0] == me && removeEdge[1] == son) || (removeEdge[0] == son && removeEdge[1] == me) ) {
					continue;
				} else {
					if ( !visited[son] ) {
						if ( hasCycle( son, me, removeEdge, adjList, visited ) )
							return true;
					} else
						return true;
				}
			}
		}

		return false;
	}

public:
	vector<int> findRedundantConnection( vector<vector<int>>& edges ) {
		int numNodes = edges.size();

		vector<vector<int>> adjList ( numNodes + 1 );
		for ( int i = 0; i < edges.size(); i++ ) {
			adjList[edges[i][0]].push_back( edges[i][1] );
			adjList[edges[i][1]].push_back( edges[i][0] );
		}

		vector<int> removeEdge;
		for ( int i = edges.size() - 1; i >= 0; i-- ) {
			removeEdge = edges[i];

			bool isIsland = false;
			vector<bool> visited ( numNodes + 1, false );
			if ( hasCycle( 1, 0, removeEdge, adjList, visited ) )
				continue;
			else {
				for ( int i = 1; i <= numNodes; i++ ) {
					if ( !visited[i] ) {
						isIsland = true;
						break;
					}
				}

				if ( !isIsland )
					break;
			}
		}

		return removeEdge;
	}
};

// method 2 : Union Find
class Solution {
private:
	int GetRoot( int target, vector<int>& parents ) {
		if ( parents[target] == target )
			return target;
		else
			return GetRoot( parents[target], parents );
	}

	void Union( int u, int v, vector<int>& parents ) {
		if ( u < v )
			parents[v] = u;
		else
			parents[u] = v;
	}

public:
	vector<int> findRedundantConnection( vector<vector<int>>& edges ) {
		int numNodes = edges.size();

		vector<int> removeEdge;
		for ( int i = edges.size() - 1; i >= 0; i-- ) {
			removeEdge = edges[i];

			vector<int> parents ( numNodes + 1 );
			for ( int j = 1; j <= numNodes; j++ )
				parents[j] = j;

			bool isCycle = false;
			for ( int currEdge = 0; currEdge < edges.size(); currEdge++ ) {
				if ( currEdge != i ) {
					int u = edges[currEdge][0], v = edges[currEdge][1];
					int uRoot = GetRoot( u, parents ), vRoot = GetRoot( v, parents );
					if ( uRoot == vRoot ) {
						isCycle = true;
						break;
					} else {
						Union( uRoot, vRoot, parents );
					}
				}
			}

			if ( !isCycle )
				break;
		}

		return removeEdge;
	}

};
