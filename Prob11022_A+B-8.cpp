/* Prob11022_A+B-8.cpp */
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	cin.tie(NULL);

	int time;

	cin >> time;

	for (int i = 1; i <= time; i++) {
		int a, b;
		cin >> a >> b;

		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}

	return 0;
}