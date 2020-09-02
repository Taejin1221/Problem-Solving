// SWExpert2058_SumDigits.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ans = 0;
	while ( n ) {
		ans += n % 10;
		n /= 10;
	}

	cout << ans;

	return 0;
}