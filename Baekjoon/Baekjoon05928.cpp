#include <iostream>

using namespace std;

int main(){
	int d, h, m;
	cin >> d >> h >> m;

	int start = 11 * 60 + 11;
	int end = ((d - 11) * 24 + h) * 60 + m;
	if (start > end)
		cout << -1;
	else
		cout << end - start;
	cout << '\n';

	return 0;
}
