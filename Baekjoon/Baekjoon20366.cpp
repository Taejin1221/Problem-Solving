// Baekjoon20366.cpp
// https://www.acmicpc.net/problem/20366
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

struct Snowman {
	int height;
	int idx1, idx2;
	
	Snowman(): height(0), idx1(0), idx2(0) {}
	Snowman(int h, int i, int j): height(h), idx1(i), idx2(j) {}
	
	bool operator<(const Snowman& s2) const {
		return height < s2.height;
	}
	
	bool isSameSnow(Snowman& s2) {
		return (idx1 == s2.idx1) || (idx1 == s2.idx2) || (idx2 == s2.idx1) || (idx2 == s2.idx2);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int snow[600];
	for (int i = 0; i < n; i++)
		cin >> snow[i];
		
	vector<Snowman> snowmen;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			snowmen.push_back(Snowman(snow[i] + snow[j], i, j));
		}
	}
	sort(snowmen.begin(), snowmen.end());
	
	int ans = 0x3f3f3f3f, len = snowmen.size();
	for (int i = 0; i < len; i++) {
		int j = i + 1;
		while (j < len && snowmen[i].isSameSnow(snowmen[j]))
			j++;

		if (j < len && !snowmen[i].isSameSnow(snowmen[j]))
			ans = min(ans, snowmen[j].height - snowmen[i].height);
	}
	
	cout << ans << '\n';

	return 0;

}
