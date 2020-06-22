// Baekjoon02577_NumberOfNumbers.cpp
#include <iostream>

using namespace std;

int main(void) {
	int A, B, C;
	int numbers[10] = { 0, };
	int target;

	cin >> A >> B >> C;
	target = A * B * C;

	while ( target > 10 ) {
		int number = target % 10;
		target /= 10;

		numbers[number]++;
	}
	numbers[target]++;

	for ( int num : numbers )
		cout << num << "\n";

	return 0;
}