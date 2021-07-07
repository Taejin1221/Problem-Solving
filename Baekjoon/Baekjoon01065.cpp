// Baekjoon01065_Hansu.cpp
#include <iostream>

using namespace std;

bool isHansu(int n) {
	int a_prev = n % 10; n /= 10;
	int a_next = n % 10;

	int difference = a_next - a_prev;
	while ( n	 != 0 ) {
		n /= 10;
		if ( difference != a_next - a_prev )
			return false;

		a_prev = a_next;
		a_next = n % 10;;
	}

	return true;
}

int main(void) {
	int n, cnt = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		if ( isHansu(i) )
			cnt++;

	cout << cnt << endl;

	return 0;
}