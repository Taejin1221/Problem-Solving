/*
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
*/

bool isPalindrome(int x) {
	if (x < 0) return false;

	int reverseNum = 0;
	int quotient = x;

	while (quotient != 0) {
		int unit  = quotient % 10;

		// Check Overflow
		if (INT_MAX / 10 < reverseNum) return false;
		else if (INT_MAX / 10 == reverseNum){
			if (INT_MAX % 10 < unit)
				return false;
		}
		else {
			reverseNum *= 10;
			reverseNum += unit;
			quotient /= 10;
		}
	}

	if (reverseNum == x) return true;
	else return false;
}