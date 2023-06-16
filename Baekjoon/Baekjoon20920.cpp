// Baekjoon20920.cpp
// https://www.acmicpc.net/problem/20920
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Word {
	string name;
	int size, freq;

	Word(): name(""), size(0), freq(0) { }
	Word(string n, int f): name(n), size(n.size()), freq(f) { }

	bool operator<(const Word& w) const {
		if (freq != w.freq) {
			return freq > w.freq;
		} else if (size != w.size) {
			return size > w.size;
		} else {
			return name.compare(w.name) < 0;
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, int> s;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if ((int)str.size() >= m) {
			if (s.find(str) == s.end())
				s.insert({ str, 1 });
			else
				s.find(str)->second++;
		}
	}

	vector<Word> words;
	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		words.push_back(Word(iter->first, iter->second));
	}

	sort(words.begin(), words.end());

	for (auto iter = words.begin(); iter != words.end(); ++iter)
		cout << iter->name << '\n';

	return 0;
}