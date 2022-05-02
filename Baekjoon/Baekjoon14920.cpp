#include <iostream>

using namespace std;

int main(){
	int c;
	cin >> c;
	
	int n = 1;
	while (c != 1) {
		if (c % 2)
			c = 3 * c + 1;
		else
			c = c / 2;
		n++;
	}
	
	cout << n << '\n';
    
    return 0;

}
