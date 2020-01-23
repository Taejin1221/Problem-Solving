/* Prob15552_FastA+B.cpp */
#include <cstdio>

int main(void) {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", a + b);
	}

	return 0;
}