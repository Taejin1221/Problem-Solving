// Baekjoon01904_01Tile.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<long long> v { 0, 1, 2 };

	int n;
	cin >> n;

	for ( int i = 3; i <= n; i++ )
		v.push_back( (v[i - 1] + v[i - 2]) % 15746 );

	cout << v[n]<< endl;


	return 0;
}
