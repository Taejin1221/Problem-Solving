// Baekjoon01016_SquareNoNoNumber.cpp
// https://www.acmicpc.net/problem/1016
#include <iostream>
#include <cstring> /* memset() */
#include <cmath> /* sqrt() */

#define MAX_ARR_SIZE 1000001

using namespace std;

int main(void) {
	long long minVal, maxVal;
	cin >> minVal >> maxVal;

	bool square[MAX_ARR_SIZE];
	memset( square, true, MAX_ARR_SIZE );
	for ( long long i = 2; i < (long long)sqrt( maxVal ) + 1; i++ ) {
		long long squ = i * i;
		long long start = minVal >= squ ? squ * ( minVal / squ ) : squ;
		if ( start < minVal )
			start += squ;

		for ( long long j = start; j <= maxVal; j += squ )
			square[j - minVal] = false;
	}

	int count = 0;
	for ( int i = 0; i <= maxVal - minVal; i++ )
		if ( square[i] )
			count++;

	cout << count << '\n';

	return 0;
}
