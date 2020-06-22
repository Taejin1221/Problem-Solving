// Prob14.c
#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */
#include <stdbool.h> /* boolean type */

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0)
		return "";

	int len = strlen(strs[0]);
	char* returnStr = calloc(len + 1, sizeof(char));

	int idx = 0, returnIdx = 0;
	bool run = true;

	while (run && strs[0][idx]) {
		for (int i = 1; i < strsSize; i++) {
			if (strs[0][idx] != strs[i][idx]) {
				run = false;
				break;
			}
		}
		if (run)
			returnStr[returnIdx++] = strs[0][idx++];
	}

	return returnStr;
}

int main(int argc, char *argv[]) {
	int strsSize = argc - 1;
	char** strs = malloc(sizeof(char*) * strsSize);
	char* str = NULL; // Just Initialization

	for (int i = 0; i < strsSize; i++)
		strs[i] = argv[i + 1];

	str = longestCommonPrefix(strs, strsSize);
	puts(str);

	free(strs);
	free(str);

	return 0;
}