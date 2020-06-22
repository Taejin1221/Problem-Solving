// Prob6.c
#include <stdio.h>
#include <stdlib.h> /* malloc(); free(); atoi(); */
#include <stdbool.h> /* boolean type */
#include <string.h> /* strlen(); */

char* convert(char* s, int numRows) {
	if (numRows == 1)
		return s;

	int len = strlen(s);

	char* rtrnStr = malloc(sizeof(char) * (len + 1));
	rtrnStr[len] = 0; // Insert '\0'

	int initIdx = 0, initX = 2 * numRows - 2;
	int x = initX, y = 0, idx = 0, rtrnIdx = 0;

	for (int i = 0; i < numRows; i++) {
		while (idx < len) {
			rtrnStr[rtrnIdx++] = s[idx];
			idx += x;

			if ((y != 0) && (idx < len)) {
				rtrnStr[rtrnIdx++] = s[idx];
				idx += y;
			}
		}
		idx = ++initIdx;
		if (idx == numRows - 1) {
			x = initX;
			y = 0;
		} else {
			x -= 2;
			y += 2;
		}
	}

	return rtrnStr;
}

int main(int argc, char const *argv[]) {
	char* s = "PAYPALISHIRING";
	char* rtrnStr = convert("A", 1);

	puts(rtrnStr);

	free(rtrnStr);
	return 0;
}