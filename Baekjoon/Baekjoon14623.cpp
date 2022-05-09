#include <iostream>

#include <vector>
#include <string>

using namespace std;

using ll = long long;

ll btoi(string s) {
	ll result = 0;
	for (int i = 0; i < s.size(); i++)
		result += (s[i] - '0') * (1LL << (s.size() - i - 1));
		
	return result;
}

int main(){
	string b1, b2;
	cin >> b1 >> b2;
	
	ll i1 = btoi(b1), i2 = btoi(b2);
	ll i3 = i1 * i2;
	
	vector<int> ans;
	while (i3) {
		ans.push_back(i3 % 2);
		i3 /= 2;
	}
	
	for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter)
		cout << *iter;

	return 0;
}
