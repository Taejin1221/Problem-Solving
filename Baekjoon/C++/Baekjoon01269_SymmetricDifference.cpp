// Baekjoon01269_SymmetricDifference.cpp
// https://www.acmicpc.net/problem/1269
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch( vector<int>& arr, int target ) {
	int start = 0, end = arr.size() - 1;
	while ( start <= end ) {
		int mid = ( start + end ) / 2;
		if ( arr[mid] == target )
			return true;
		else if ( arr[mid] < target )
			start = mid + 1;
		else
			end = mid - 1;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> A ( n ), B ( m );
	for ( int i = 0; i < n; i++ )
		cin >> A[i];

	for ( int i = 0; i < m; i++ )
	 	cin >> B[i];

	sort( A.begin(), A.end() );
	sort( B.begin(), B.end() );

	vector<int> ans;
	for ( int& value : A )
		if ( !BinarySearch( B, value ) )
			ans.push_back( value );

	for ( int& value : B )
		if ( !BinarySearch( A, value ) )
			ans.push_back( value );

	sort( ans.begin(), ans.end() );

	if ( ans.size() == 0 )
		cout << 0 << '\n';
	else {
		int len = 1;
		for ( int i = 1; i < ans.size(); i++ )
			if ( ans[i - 1] != ans[i] )
				len++;

		cout << len << '\n';
	}

	return 0;
}