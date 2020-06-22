/* Prob0088_MergeSortedArray.c */
typedef int * intPtr, * intArr;

void merge(intArr nums1, int nums1Size, int m, intArr nums2, int nums2Size, int n) {
	intPtr nums1Cpy = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) nums1Cpy[i] = nums1[i];

	int idx_nums1 = 0, idx_nums2 = 0, idx_origin = 0;
	while (idx_nums1 < m && idx_nums2 < n)
		nums1[idx_origin++] = (nums1Cpy[idx_nums1] < nums2[idx_nums2] ?
			nums1Cpy[idx_nums1++] : nums2[idx_nums2++]);

	while (idx_nums1 < m)
		nums1[idx_origin++] = nums1Cpy[idx_nums1++];
	while (idx_nums2 < n)
		nums1[idx_origin++] = nums2[idx_nums2++];
}