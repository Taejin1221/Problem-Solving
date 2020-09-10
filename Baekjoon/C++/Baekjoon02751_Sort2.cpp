// Baekjoon02751_Sort2.cpp
// https://www.acmicpc.net/problem/2751
#include <iostream>

using namespace std;

void Merge( int arr[], int start, int mid, int end ) {
	int leftSize = mid - start + 1, rightSize = end - ( mid + 1 ) + 1;
	int* leftArr = new int[leftSize];
	int* rightArr = new int[rightSize];

	for ( int i = start, idx = 0; i <= mid; i++, idx++ )
		leftArr[idx] = arr[i];

	for ( int i = mid + 1, idx = 0; i <= end; i++, idx++ )
		rightArr[idx] = arr[i];

	int leftIdx = 0, rightIdx = 0, arrIdx = start;
	while ( leftIdx < leftSize && rightIdx < rightSize )
		arr[arrIdx++] = ( leftArr[leftIdx] <= rightArr[rightIdx] ) ? leftArr[leftIdx++] : rightArr[rightIdx++];

	while ( leftIdx < leftSize )
		arr[arrIdx++] = leftArr[leftIdx++];

	while ( rightIdx < rightSize )
		arr[arrIdx++] = rightArr[rightIdx++];

	delete[] leftArr;
	delete[] rightArr;
}

void MergeSort( int arr[], int start, int end ) {
	if ( start < end ) {
		int mid = ( start + end ) / 2;
		MergeSort( arr, start, mid );
		MergeSort( arr, mid + 1, end );
		Merge( arr, start, mid, end );
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	// Method 1
	MergeSort( arr, 0, n - 1 );

	// Method 2
	sort( arr, arr + n );

	for ( int i = 0; i < n; i++ )
		cout << arr[i] << '\n';

	return 0;
}