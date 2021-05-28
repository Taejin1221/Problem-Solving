// Baekjoon17413_FlipWord2.cpp
// https://www.acmicpc.net/problem/17413
#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
	char string[100'001];
	scanf("%[^\n]s", string);

	int n = strlen( string );

	int prevSpace = -1;

	for ( int i = 0; i <= n; i++ ) {
		if ( string[i] == ' ' || string[i] == '\0' ) {
			for ( int j = i - 1; j > prevSpace; j-- )
				printf("%c", string[j]);
			prevSpace = i;
			printf(" ");
		} else if ( string[i] == '<' ) {
			for ( int j = i - 1; j > prevSpace; j-- )
				printf("%c", string[j]);

			while ( string[i] != '>' ) {
				printf("%c", string[i] );
				i++;
			}
			printf("%c", string[i]);
			prevSpace = i;
		}
	}

	printf("\n");

	return 0;
}