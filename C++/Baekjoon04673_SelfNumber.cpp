// Baekjoon04673_SelfNumber.cpp
#include <iostream>

#define MAX 10001

using namespace std;

int d(int n) {
	int val = n;
	while ( n > 0 ) {
		val += n % 10;
		n /= 10;
	}

	return val;
}

int main(void) {
	bool selfNumber[MAX];
	memset(selfNumber, true, sizeof(selfNumber));

	for (int i = 1; i < MAX; i++) {
		if ( selfNumber[i] ) cout << i << endl;

		int d_val = d(i);
		while ( d_val < 10001 ) {
			if ( !selfNumber[d_val] ) break;
			selfNumber[d_val] = false;
			d_val = d(d_val);
		}
	}

	return 0;
}