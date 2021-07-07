// Prob10951_A+B-4.cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF) {
		cout << a + b << "\n";
	}

	printf("%d\n", EOF);

	return 0;
}