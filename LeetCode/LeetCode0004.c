// Prob0004_MedianOfTwoSortedArrays.c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int *result = malloc(sizeof(int) * (nums1Size + nums2Size));
	int resIndex = 0;

	for (int i = 0; i < nums1Size; i++)	result[resIndex++] = nums1[i];
	for (int i = 0; i < nums2Size; i++)	result[resIndex++] = nums2[i];

	for (int i = (resIndex - 1); i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (result[j] > result[j + 1]) {
				int temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}

	int val = resIndex / 2;
	double returnValue = 0;
	if (!(resIndex % 2))
		returnValue =  ((result[val - 1] + result[val]) / (double)2);
	else
		returnValue =  (double)result[val];

	free(result);

	return returnValue;
}
