// Baekjoon01759.cpp
// https://www.acmicpc.net/problem/1759
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

int l, c;
char characters[15];
vector<string> ans;

bool isValid(string& str) {
	int numVowel = 0;
	for (char c : str) {
		for (char v : vowels) {
			if (c == v) {
				numVowel++;
				break;
			}
		}
	}
	
	return (1 <= numVowel && numVowel <= l - 2 ) ? true : false;
}

void solve(string& curr, int idx) {
	if (curr.size() == l) {
		if (isValid(curr))
			ans.push_back(curr);
	} else {
		for (int i = idx; i < c; i++) {
			curr.push_back(characters[i]);
			solve(curr, i + 1);
			curr.pop_back();
		}
	}
}

int main(){
	cin >> l >> c;
	
	for (int i = 0; i < c; i++)
		cin >> characters[i];
	sort(characters, characters + c);
	
	string curr;
	solve(curr, 0);
	
	for (int i = 0; i < ans.size(); i++)
	cout << ans[i] << '\n';
    
	return 0;

}
