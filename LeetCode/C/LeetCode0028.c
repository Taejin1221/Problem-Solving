#include <stdio.h>

int strStr(char * haystack, char * needle){
	int len_haystack = 0;
	int len_needle = 0;

	while (haystack[len_haystack]) len_haystack++;
	while (needle[len_needle]) len_needle++;

	if (len_haystack < len_needle) return -1;
	if (len_needle == 0) return 0;

	int i;
	for (int index_hay = 0; index_hay < len_haystack; index_hay++) {
		for (i = 0; i < len_needle; i++)
			if (haystack[index_hay + i] != needle[i]) break;
		if (i == len_needle) return index_hay;
	}

	return -1;
}

int main(int argc, char *argv[]) {
	printf("%d\n", strStr(argv[1], argv[2]));
// int main(void) {
	// printf("%d\n", strStr("", "a"));

	return 0;
}