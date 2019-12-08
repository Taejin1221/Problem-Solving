/* Prob2739_Gugudan.cpp */
#include <iostream>

using namespace std;

int main(void) {
	int num;

	cin >> num;

	for (int i = 1; i <= 9; i++)
		cout << num << " * " << i << " = " << num * i << endl;

	return 0;
}