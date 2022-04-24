#include <iostream>

#include <vector>
#include <string>

using namespace std;

int main(){
	vector<bool> ans, origin;

	string bin;
	cin >> bin;

	for (auto iter = bin.rbegin(); iter != bin.rend(); ++iter) {
		bool curr = *iter == '1';
		ans.push_back(curr);
		origin.push_back(curr);
	}

	for (int i = 0; i < 16; i++) {
		int j = 0;
		bool carry = false;
		while (j < origin.size()) {
			int oneNum = ans[j] + origin[j] + carry;
			if (oneNum == 1) {
				ans[j] = true;
				carry = false;
			} else if (oneNum == 2) {
				ans[j] = false;
				carry = true;
			} else if (oneNum == 3) {
				ans[j] = true;
				carry = true;
			}
		
			j++;
		}
		
		while (j < ans.size()) {
			bool newCarry = ans[j] & carry;
			ans[j] = ans[j] ^ carry;
			carry = newCarry;
			j++;
		}
		
		if (carry)
			ans.push_back(true);
	}
	
	for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter) {
		cout << *iter;
	}
	cout << endl;

	return 0;
}
