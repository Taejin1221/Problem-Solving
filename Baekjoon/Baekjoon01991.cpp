// Baekjoon01991_TreeTraversal.cpp
// https://www.acmicpc.net/problem/1991
#include <cstdio>

struct TreeNode {
	int left, right;
};

TreeNode tree[26];

void PreorderTraversal( int root );
void InorderTraversal( int root );
void PostorderTraversal( int root );

int main(void) {
	int n;
	scanf("%d", &n); getchar();

	for ( int i = 0; i < n; i++ ) {
		char root, left, right;
		scanf("%c %c %c", &root, &left, &right); getchar();

		int rootIdx = root - 'A';
		int leftIdx = left - 'A';
		int rightIdx = right - 'A';

		if ( left != '.' )
			tree[rootIdx].left = leftIdx;
		else
			tree[rootIdx].left = -1;

		if ( right != '.' )
			tree[rootIdx].right = rightIdx;
		else
			tree[rootIdx].right = -1;
	}

	PreorderTraversal( 0 ); puts("");
	InorderTraversal( 0 ); puts("");
	PostorderTraversal( 0 ); puts("");

	return 0;
}

void PreorderTraversal( int root ) {
	if ( root != -1) {
		printf("%c", root + 'A');
		PreorderTraversal( tree[root].left );
		PreorderTraversal( tree[root].right );
	}
}

void InorderTraversal( int root ) {
	if ( root != -1) {
		InorderTraversal( tree[root].left );
		printf("%c", root + 'A');
		InorderTraversal( tree[root].right );
	}
}

void PostorderTraversal( int root ) {
	if ( root != -1) {
		PostorderTraversal( tree[root].left );
		PostorderTraversal( tree[root].right );
		printf("%c", root + 'A');
	}
}