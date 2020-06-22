// Baekjoon01541_LostBracket.cpp
// https://www.acmicpc.net/problem/1541
#include <cstdio>
#include <cstring>

int main(void) {
	char expression[51];
	scanf("%s", expression);

	char operators[50];
	int nums[50] = { 0, }, numIdx = 0, operIdx = 0;

	for ( int i = 0; i < strlen( expression ); i++ ) {
		if ( expression[i] != '-' && expression[i] != '+' ) {
			nums[numIdx] *= 10;
			nums[numIdx] += expression[i] - 48;
		} else {
			operators[operIdx++] = expression[i];
			numIdx++;
		}
	}

	int numsLen = numIdx + 1, operLen = operIdx;
	numIdx = operIdx = 0;

	int result1 = nums[numIdx++], result2 = 0;
	while ( operIdx < operLen && numIdx < numsLen&& operators[operIdx++] != '-' )
		result1 += nums[numIdx++];
	while ( numIdx < numsLen )
		result2 += nums[numIdx++];

	printf("%d\n", result1 - result2 );

	return 0;
}