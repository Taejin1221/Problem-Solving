// SWExpert2068_MaxValue.cpp
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for ( int time = 1; time <= t; time++  ) {
		int maxVal = 0;
		for ( int i = 0; i < 10; i++ ) {
			int temp;
			cin >> temp;

			maxVal = max( maxVal, temp );
		}

		cout << '#' << time << ' ' << maxVal << '\n';
	}

	return 0;
}