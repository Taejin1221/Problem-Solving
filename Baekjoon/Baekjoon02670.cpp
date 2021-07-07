// Baekjoon02670_MaximumSubarrayMultiply.cpp
// https://www.acmicpc.net/problem/2670
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf( "%d", &n );

	double arr[10'000];
	for ( int i = 0; i < n; i++ )
		scanf( "%lf", &arr[i] );

	double sum = arr[0], maxVal = arr[0];
	for ( int i = 1; i < n; i++ ) {
		sum = max( arr[i], sum * arr[i] );
		maxVal = max( maxVal, sum );
	}

	printf("%.3f\n", maxVal);

	return 0;
}
