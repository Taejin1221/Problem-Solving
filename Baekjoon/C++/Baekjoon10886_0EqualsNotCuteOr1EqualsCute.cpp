// Baekjoon10886_0=notcute/1=cute.cpp
// https://www.acmicpc.net/problem/10886
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int count0 = 0, count1 = 0;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
		if ( temp )
			count1++;
		else
			count0++;
	}

	if ( count0 > count1 )
		cout << "Junhee is not cute!\n";
	else
		cout << "Junhee is cute!\n";

	return 0;
}