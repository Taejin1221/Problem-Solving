// Baekjoon16198.cpp
// https://www.acmicpc.net/problem/16198
#include <iostream>

#include <vector>

using namespace std;

int n, ans;
vector<int> energies;

void collectEnergy(vector<int>& perm) {
	vector<int> tempEnergies;
	for (int i = 0; i < n; i++)
		tempEnergies.push_back(energies[i]);

	int results = 0;
	for (int i = 0; i < perm.size(); i++) {
		int targetIdx = perm[i];
		results += tempEnergies[targetIdx - 1] * tempEnergies[targetIdx + 1];
		tempEnergies.erase(tempEnergies.begin() + targetIdx);
	}

	ans = max(ans, results);
}

void backtracking(vector<int>& perm) {
	if (perm.size() == n - 2) {
		collectEnergy(perm);
	} else {
		for (int i = 1; i < n - perm.size() - 1; i++) {
			perm.push_back(i);
			backtracking(perm);
			perm.pop_back();
		}
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int energy;
		cin >> energy;
		energies.push_back(energy);
	}

	vector<int> perm;
	backtracking(perm);

	cout << ans << '\n';

	return 0;
}