// Prob15.c
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int** threeSum(int* nums, int numSize, int* returnSize, int** returnColumnSizes) {
	int num1, num2, num3;
	int* queue[100];
	*returnSize = 0;

	for (num1 = 0; num1 < numSize; num1++) {
		for (num2 = num1 + 1; num2 < numSize; num2++) {
			for (num3 = num3 + 1; num3 < numSize; num3++) {
				int* newArr = malloc(sizeof(int) * 3);
				newArr[0] = num1;
				newArr[1] = num2;
				newArr[2] = num3;
				queue[(*returnSize)++] = newArr;
			}
		}
	}

	int maxSize = *returnSize;
	int** returnArrays = malloc(sizeof(int *) * maxSize);
	for (int i = 0; i < maxSize; i++)
		returnArrays[i] = queue[i];

	return returnArrays;
}