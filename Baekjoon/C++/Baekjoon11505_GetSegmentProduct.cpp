// Baekjoon11505_GetSegmentProduct.cpp
// https://www.acmicpc.net/problem/11505
#include <iostream>

#define endl '\n'
#define DIVISOR 1'000'000'007
#define MAX_ARR_SIZE 1'000'000
#define MAX_TREE_SIZE 4'000'000

using namespace std;

struct Range {
	int start, end;
	Range() {}
	Range( int e ): start(0), end(e - 1) {}
	Range( int s, int e ): start(s), end(e) {}
	bool isLeaf();
	int getMid();
	void minus();
};

int targetIdx, targetValue;
Range segment;
int arr[MAX_ARR_SIZE];
long long tree[MAX_TREE_SIZE];

void MakeTree( int me, Range range );
void UpdateTree( int me, Range range );
int GetSegmentProduct( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range whole = Range( n );
	MakeTree( 1, whole );

	int t = m + k;
	while ( t-- ) {
		int opr;
		cin >> opr;

		if ( opr == 1 ) {
			cin >> targetIdx >> targetValue;
			targetIdx--;

			UpdateTree( 1, whole );
		} else {
			cin >> segment.start >> segment.end;
			segment.minus();

			cout << GetSegmentProduct( 1, whole ) << endl;
		}
	}

	return 0;
}

// Function
void MakeTree( int me, Range range ) {
	if ( range.isLeaf() )
		tree[me] = arr[range.start];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( range.start, mid ) );
		MakeTree( right, Range( mid + 1, range.end ) );

		tree[me] = (long long)tree[left] * tree[right] % DIVISOR;
	}
}

void UpdateTree( int me, Range range ) {
	if ( range.end < targetIdx || targetIdx < range.start )
		return;
	
	if ( range.isLeaf() ) {
		if ( range.start == targetIdx )
			tree[me] = targetValue;
		else
			return;
	}
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, Range( range.start, mid ) );
		UpdateTree( right, Range( mid + 1, range.end ) );

		tree[me] = (long long)tree[left] * tree[right] % DIVISOR;
	}
}

int GetSegmentProduct( int me, Range range ) {
	if ( range.end < segment.start || segment.end < range.start )
		return 1;
	else if ( segment.start <= range.start && range.end <= segment.end )
		return tree[me];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		int leftProduct = GetSegmentProduct( left, Range( range.start, mid ) );
		int rightProduct = GetSegmentProduct( right, Range( mid + 1, range.end ) );

		return ( (long long)leftProduct * rightProduct ) % DIVISOR;
	}
}

// Method
bool Range::isLeaf() {
	return ( start == end );
}

int Range::getMid() {
	return ( start + end ) / 2;
}

void Range::minus() {
	start--; end--;
}