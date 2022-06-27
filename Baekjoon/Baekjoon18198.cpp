#include <iostream>

#include <string>

using namespace std;

int main(){
	string info;
	cin >> info;

	int a = 0, b = 0;
	char winner;
	
	for (int i = 0; i < info.size(); i += 2) {
		if (info[i] == 'A')
			a += info[i + 1] - '0';
		else
			b += info[i + 1] - '0';
		
		if (a >= 11 && (a - b) >= 2) {
			winner = 'A';
			break;
		} else if (b >= 11 &&(b - a) >= 2) {
			winner = 'B';
			break;
		}
	}
	
	cout << winner << '\n';
	

	return 0;
}
