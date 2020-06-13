// Baekjoon01259_PalindromeNumber.cpp
// https://www.acmicpc.net/problem/1259
#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
	char num[6];
	scanf("%s", num);
	while ( strcmp(num, "0") != 0 ) {
		bool isPaline = true;
		
		int len = strlen( num );
		for ( int i = 0; i < len / 2; i++ ) {
			if ( num[i] != num[len - 1 - i] ) {
				isPaline = false;
				break;
			}
		}

		if ( isPaline ) puts("yes");
		else puts("no");

		scanf("%s", num);
	}

	return 0;
}