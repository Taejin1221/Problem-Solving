#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int reverse(int x) {
	int num = x;
	long long rev = 0;
	bool isNegative = false;
	if (x < 0) {
		isNegative = true;
		num *= -1;
	}

	while (num) {
		int temp = num % 10;
		num /= 10;
		rev *= 10;

		rev += temp;
	}

	if (isNegative)
		rev *= -1;

	if (rev < INT_MIN || rev > INT_MAX)
		return 0;
	else return (int)rev;
}

int main(void) {
	int x;

	scanf("%d", &x);

	printf("%d\n", reverse(x));

	return 0;
}