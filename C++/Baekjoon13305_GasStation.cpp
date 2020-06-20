// Baekjoon13305_GasStation.cpp
// htts://www.acmicpc.net/problem/13305
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cityNum;
	cin >> cityNum;

	int prices[100000];
	int distances[100000];
	for ( int i = 0; i < cityNum - 1; i++ )
		cin >> distances[i];
	for ( int i = 0; i < cityNum; i++ )
		cin >> prices[i];

	int prevPrice = prices[0];
	long totalCost = 0, prevDistance = distances[0];
	for ( int i = 1; i < cityNum - 1; i++ ) {
		if ( prices[i] < prevPrice ) {
			totalCost += prevPrice * prevDistance;
			prevPrice = prices[i];
			prevDistance = 0;
		}

		prevDistance += distances[i];
	}

	totalCost += prevPrice * prevDistance;

	cout << totalCost << '\n';

	return 0;
}