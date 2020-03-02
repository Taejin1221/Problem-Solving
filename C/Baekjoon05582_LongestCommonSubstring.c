// Prob5582_LongestCommonSubstring.c
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[4001];
	char str2[4001];
	int table[4001][4001] = { 0, };

	scanf("%s", str1);
	scanf("%s", str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int max = 0;

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = 0;

			if (max < table[i][j])
				max = table[i][j];
		}
	}

	printf("%d\n", max);

	return 0;
}
