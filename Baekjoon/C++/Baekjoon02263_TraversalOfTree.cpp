// Baekjoon02263_TraversalOfTree.cpp
// https://www.acmicpc.net/problem/2263
#include <iostream>
#include <vector>

using namespace std;

void PrintInorder(vector<int>& in, vector<int>& post) {
	if ( in.size() == 0 )
		return;

	int root = post[post.size() - 1];
	vector<int> leftIn, rightIn, leftPost, rightPost;

	bool isLeft = true;
	for ( int& i : in ) {
		if ( i == root ) {
			isLeft = false;
			continue;
		}

		if ( isLeft )
			leftIn.push_back( i );
		else
			rightIn.push_back( i );
	}

	int idx = 0;
	while ( idx < leftIn.size() )
		leftPost.push_back(post[idx++]);

	while ( idx < rightIn.size() + leftIn.size() + 1 )
		rightPost.push_back(post[idx++]);

	PrintInorder( leftIn, leftPost );
	cout << root << ' ';
	PrintInorder( rightIn, rightPost );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> in, post;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		in.push_back( temp );
	}

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		post.push_back( temp );
	}

	PrintInorder( in, post );
	cout << '\n';

	return 0;
}