// Baekjoon13224.cpp
// https://www.acmicpc.net/problem/13224
#include <iostream>

#include <string>

using namespace std;

void swap(int& a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	string inst;
	cin >> inst;

	int cup[3] = { 1, 0, 0 };
	for (int i = 0; i < inst.size(); i++) {
		if (inst[i] == 'A')
			swap(cup[0], cup[1]);
		else if (inst[i] == 'B')
			swap(cup[1], cup[2]);
		else
			swap(cup[0], cup[2]);
	}

	if (cup[0])
		cout << 1;
	else if (cup[1])
		cout << 2;
	else
		cout << 3;
	cout << '\n';

	return 0;
}