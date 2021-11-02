// Codeforces_1607E.cpp
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool moveTo(pii segment[], int direction, int size) {
	segment[0].first += direction;
	segment[1].first += direction;

	if (segment[0].first < 1) {
		segment[0].first = 1;
		segment[0].second++;
	}

	if (segment[1].first > size) {
		segment[1].first = size;
		segment[1].second--;
	}

	if (segment[0].second > segment[1].second)
		return false;
	else
		return true;
}

void solveTestCase() {
	int row, col;
	cin >> row >> col;

	string command;
	cin >> command;

	pii rowSegment[2] = { { 1, 1 }, { row, row } };
	pii colSegment[2] = { { 1, 1 }, { col, col } };

	bool currMoveResult = false;
	pii prevRowSegment[2], prevColSegment[2];
	for (char& c : command) {
		prevRowSegment[0] = rowSegment[0];
		prevRowSegment[1] = rowSegment[1];
		prevColSegment[0] = colSegment[0];
		prevColSegment[1] = colSegment[1];
		if (c == 'U' || c == 'D')
			currMoveResult = moveTo(rowSegment, (c == 'U') ? -1 : 1, row);
		else
			currMoveResult = moveTo(colSegment, (c == 'L') ? -1 : 1, col);

		if (!currMoveResult)
			break;
	}

	if (currMoveResult)
		cout << rowSegment[0].second << ' ' << colSegment[0].second << '\n';
	else
		cout << prevRowSegment[0].second << ' ' << prevColSegment[0].second << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
