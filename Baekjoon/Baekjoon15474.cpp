#include <iostream>

using namespace std;

int main(){
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	int minXSet = n / a + (n % a ? 1 : 0), minYSet = n / c + (n % c ? 1 : 0);
	cout << min(minXSet * b, minYSet * d);

	return 0;
}
