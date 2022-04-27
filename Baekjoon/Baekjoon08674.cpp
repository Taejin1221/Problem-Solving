#include <iostream>

using namespace std;

using ll = long long;

int main(){
	ll row, col;
	cin >> row >> col;

	ll halfRow = row / 2, halfCol = col / 2;

	ll selectRow = (row - halfRow) *  col - halfRow * col;
	ll selectCol = (col - halfCol) * row - halfCol * row;

	cout << min(selectRow, selectCol) << endl;

	return 0;
}
