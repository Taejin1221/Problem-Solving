// Baekjoon16987.cpp
// https://www.acmicpc.net/problem/16987
#include <iostream>

#include <vector>

using namespace std;

struct Egg {
	int durability, weight;
	Egg(): durability(0), weight(0) { }
	Egg(int d, int w): durability(d), weight(w) { }
};

int ans;

void hitEgg(vector<Egg> eggs, int curr, int breakCount) {
	while (curr < eggs.size() && eggs[curr].durability <= 0)
		curr++;

	if (curr == eggs.size()) {
		ans = max(ans, breakCount);

		return;
	}

	for (int i = 0; i < eggs.size(); i++) {
		if (i != curr && eggs[i].durability > 0) {
			eggs[i].durability -= eggs[curr].weight;
			eggs[curr].durability -= eggs[i].weight;

			int currBreak = 0;
			if (eggs[i].durability <= 0)
				currBreak++;
			if (eggs[curr].durability <= 0)
				currBreak++;

			hitEgg(eggs, curr + 1, breakCount + currBreak);
			eggs[i].durability += eggs[curr].weight;
			eggs[curr].durability += eggs[i].weight;
		}
	}

	ans = max(ans, breakCount);
}

int main(void) {
	int n;
	cin >> n;

	vector<Egg> eggs;
	for (int i = 0; i < n; i++) {
		int dura, weig;
		cin >> dura >> weig;

		eggs.push_back(Egg(dura, weig));
	}

	hitEgg(eggs, 0, 0);

	cout << ans << '\n';

	return 0;
}