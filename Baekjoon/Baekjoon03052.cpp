// Baekjoon03052_Remainder.cpp
#include <iostream>

using namespace std;

int main(void) {
	int cnt = 0;
	bool arr[42] = { false, };

	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;

		int remainder = a % 42;
		if (!arr[remainder]) {
			arr[remainder] = true;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}