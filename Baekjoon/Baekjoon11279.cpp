// Baekjoon11279_MaxHeap.cpp
// https://www.acmicpc.net/problem/11279
#include <iostream>

using namespace std;

int size = 0;
int heap[100001];

void Swap( int* a, int* b );
void Push( int x );
int Pop();
void Heapify( int idx );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int time;
	cin >> time;

	while ( time-- ) {
		int oper;
		cin >> oper;

		if ( oper )
			Push( oper );
		else
			cout << Pop( ) << '\n';
	}

	return 0;
}

void Swap( int* a, int* b ) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Push( int x ) {
	heap[++size] = x;
	int mom = size / 2, son = size;
	while ( mom > 0 && heap[mom] < heap[son] ) {
		Swap( heap + mom, heap + son );
		son = mom;
		mom /= 2;
	}
}

int Pop( ) {
	if ( size == 0 )
		return 0;
	else {
		int rtrnVal = heap[1];
		heap[1] = heap[size--];

		Heapify( 1 );

		return rtrnVal;
	}
}

void Heapify( int idx ) {
	int leftIdx = idx * 2, rightIdx = idx * 2 + 1;

	int maxIdx;
	if ( rightIdx <= size )
		maxIdx = ( heap[leftIdx] > heap[rightIdx] ? leftIdx : rightIdx );
	else if ( leftIdx <= size )
		maxIdx = leftIdx;
	else
		return;

	if ( heap[maxIdx] > heap[idx] ) {
		Swap( heap + maxIdx, heap + idx );
		Heapify( maxIdx );
	}
}