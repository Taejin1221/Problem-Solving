// IUPC_A.cpp
#include <iostream>

using namespace std;

int main(void) {
	char mbti[5];
	cin >> mbti;

	if ( mbti[0] == 'E' )
		cout << 'I';
	else
		cout << 'E';

	if ( mbti[1] == 'S' )
		cout << 'N';
	else
		cout << 'S';

	if ( mbti[2] == 'T' )
		cout << 'F';
	else
		cout << 'T';

	if ( mbti[3] == 'J' )
		cout << 'P';
	else
		cout << 'J';

	return 0;
}