// Prob16.c
#include <stdio.h>

#define ABS(x) (((x) >= (0)) ? (x) : -(x))

int threeSumClosest(int* nums, int numsSize, int target) {
	int idx1, idx2, idx3;
	int rtrnVal = 100;

	for (idx1 = 0; idx1 < numsSize; idx1++) {
		for (idx2 = idx1 + 1; idx2 < numsSize; idx2++) {
			for (idx3 = idx2 + 1; idx3 < numsSize; idx3++) {
				int threeSum = nums[idx1] + nums[idx2] + nums[idx3];
				if (ABS(threeSum - target) < ABS(rtrnVal - target))
					rtrnVal = threeSum;
			}
		}
	}

	return rtrnVal;
}