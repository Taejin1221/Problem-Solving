// SCPC_2.cpp
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		int n, t;
		cin >> n >> t;
		char B[50'001] = { 0, };
		for (int i = 1; i <= n; i++)
			cin >> B[i];

		char A[50'001];
		fill(A + 1, A + n + 1, -1);
		for (int i = 1; i <= t; i++) {
			if (i + t <= n)
				A[i + t] = B[i];
		}
		for (int i = n - t + 1; i <= n; i++) {
			if (i - t >= 1)
				A[i - t] = B[i];
		}
		for (int i = 1; i <= n; i++) {
			if (B[i] == '0') {
				if (i > t)
					A[i - t] = '0';
				if (i <= n - t)
					A[i + t] = '0';
			}
		}

		for (int i = t + 1; i <= n - t; i++) {
			if (B[i] == '1') {
				if (A[i - t] == '1' || A[i + t] == '1')
					continue;
				else if (A[i - t] == -1 && A[i + t] == -1)
					A[i + t] = '1';
				else if (A[i - t] == -1 && A[i + t] == '0')
					A[i - t] = '1';
				else if (A[i - t] == '0' && A[i + t] == -1)
					A[i + t] = '1';
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
		for (int i = 1; i <= n; i++) {
			if (A[i] == -1)
				cout << '0';
			else
				cout << A[i];
		}
		cout << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}