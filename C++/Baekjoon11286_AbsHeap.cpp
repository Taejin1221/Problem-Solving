// Baekjoon11286_MinHeap.cpp
// https://www.acmicpc.net/problem/11286
#include <iostream>

#define ABS(x) (((x) < 0 ) ? (-(x)) : x)

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
	while ( mom > 0 ) {
		int absMom = ABS( heap[mom] ), absSon = ABS( heap[son] );
		if ( absMom > absSon) {
			Swap( heap + mom, heap + son );
		} else if ( absMom == absSon ) {
			if ( heap[mom] > heap[son] ) {
				Swap( heap + mom, heap + son );
			}
		} else break;
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

	int minIdx;
	if ( rightIdx <= size ) {
		int absLeft = ABS( heap[leftIdx] ), absRight = ABS( heap[rightIdx] );
		if ( absLeft < absRight )
			minIdx = leftIdx;
		else if ( absLeft > absRight )
			minIdx = rightIdx;
		else {
			minIdx = ( heap[leftIdx] < heap[rightIdx] ? leftIdx : rightIdx );
		}
	}
	else if ( leftIdx <= size )
		minIdx = leftIdx;
	else
		return;

	int absMin = ABS( heap[minIdx] ), absIdx = ABS( heap[idx] );
	if ( absMin < absIdx ) {
		Swap( heap + minIdx, heap + idx );
		Heapify( minIdx );
	} else if ( absMin == absIdx ) {
		if ( heap[minIdx] < heap[idx] ) {
			Swap( heap + minIdx, heap + idx );
			Heapify( minIdx );
		}
	}
}