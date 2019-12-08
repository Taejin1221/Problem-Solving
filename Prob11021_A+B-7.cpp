/* Prob11021_A+B-7.cpp */
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	int time;

	cin >> time;

	for (int i = 1; i <= time; i++) {
		int a, b;
		cin >> a >> b;

		printf("Case #%d: %d\n", i, a + b);
	}

	return 0;
}