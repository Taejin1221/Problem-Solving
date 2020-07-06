// Baekjoon04354_StringSquare.cpp
// https://www.acmicpc.net/problem/4354
#include <cstdio>
#include <cstring>

#define MAX_STR_SIZE 1'000'001

int main(void) {
	char str[MAX_STR_SIZE];
	scanf("%s", str); getchar();
	while ( str[0] != '.' ) {
		int n = strlen(str);

		int fail[MAX_STR_SIZE] = { 0, };

		int j = 0;
		for ( int i = 1; i < n; i++ ) {
			while ( j > 0 && str[i] != str[j] )
				j = fail[j - 1];

			if ( str[i] == str[j] )
				fail[i] = ++j;
		}

		int non0 = n;
		while ( non0 >= 0 && fail[non0 - 1] )
			non0--;

		if ( j % non0 )
			printf("1\n");
		else
			printf("%d\n", n / non0 );

		scanf("%s", str); getchar();
	}

	return 0;
}