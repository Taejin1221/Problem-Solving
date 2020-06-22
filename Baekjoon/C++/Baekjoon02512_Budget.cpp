// Baekjoon02512_Budget.cpp
// https://www.acmicpc.net/problem/2512
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie( NULL );

	int n, totalBudget;
	cin >> n;

	long long sumBudget = 0;
	int budgets[10000], maxBudget = 0;
	for ( int i = 0; i < n; i++ ) {
		cin >> budgets[i];
		sumBudget += budgets[i];
		if ( maxBudget < budgets[i] )
			maxBudget = budgets[i];
	}

	cin >> totalBudget;

	if ( sumBudget <= totalBudget )
		cout << maxBudget;
	else {
		int left = 1, right = maxBudget - 1;
		while ( left + 1 < right ) {
			sumBudget = 0;
			int mid = ( left + right ) / 2;
			for ( int i = 0; i < n; i++ )
				sumBudget += ( mid < budgets[i] ? mid : budgets[i] );

			if ( sumBudget > totalBudget )
				right = mid;
			else
				left = mid;
		}

		cout << left << '\n';
	}

	return 0;
}