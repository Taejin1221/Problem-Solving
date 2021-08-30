// SCPC_1.cpp
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

bool visited[100'001];
vector<int> adjList[100'001];
void dfs(int start) {
	visited[start] = true;
	for (int& adj : adjList[start])
		if (!visited[adj])
			dfs(adj);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

		int n;
		cin >> n;

		fill(visited + 1, visited + n + 1, false);
		for (int i = 1; i <= n; i++)
			adjList[i].clear();

		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;

			if (temp + i <= n) {
				int adj = temp + i;
				adjList[i].push_back(adj);
				adjList[adj].push_back(i);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				Answer++;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}