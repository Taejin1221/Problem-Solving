// Baekjoon02263_TraversalOfTree.cpp
// https://www.acmicpc.net/problem/2263
#include <iostream>

#define MAX_SIZE 100'000

using namespace std;

struct Range {
	int start, end;
	Range( ): start(0), end(0) { }
	Range( int s, int e ): start(s), end(e) { }
};

int inorder[MAX_SIZE], postorder[MAX_SIZE];

void MakePreorder( Range in, Range post ) {
	if ( in.start > in.end )
		return;
	else {
		int rootVal = postorder[post.end];

		int rootIdx = in.start;
		while (  rootIdx <= in.end && inorder[rootIdx] != rootVal )
			rootIdx++;

		int leftSize = rootIdx - in.start, rightSize = in.end - rootIdx;

		cout << rootVal << ' ';
		MakePreorder( Range( in.start, rootIdx - 1 ), Range( post.start, post.start + leftSize - 1 ) );
		MakePreorder( Range( rootIdx + 1, in.end ), Range( post.start + leftSize, post.end - 1 ) );
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> inorder[i];

	for ( int i = 0; i < n; i++ )
		cin >> postorder[i];

	MakePreorder( Range( 0, n - 1 ), Range( 0, n - 1 ) );
	cout << '\n';

	return 0;
}
