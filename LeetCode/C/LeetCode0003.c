#include <stdio.h>
#include <stdbool.h> // boolean type
#include <string.h> // strlen(), strcpy()

int lengthOfLongestSubstring(char* s) {
	int lenStr = strlen(s);
	if (lenStr == 0) return 0;

	int subLen = 0, max = 0, front = 0;
	for (int i = 0; i < lenStr; i++) {
		for (int j = front; j < i; j++) {
			if (s[i] == s[j]) {
				max = max < subLen ? subLen : max;
				subLen -= j + 1 - front;
				front = j + 1;
				break;
			}
		}
		subLen++;
	}

	max = max < subLen ? subLen : max;

	return max;
}

int main(int argc, char const *argv[]) {
//int main(void) {
	char str1[100];
	strcpy(str1, argv[1]);
	// strcpy(str1, "");
	printf("%d\n", lengthOfLongestSubstring(str1));

	return 0;
}