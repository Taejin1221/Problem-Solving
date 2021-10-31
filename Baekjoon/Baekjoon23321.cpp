// Hongik_B.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string picture[5];
	for (int i = 0; i < 5; i++)
		cin >> picture[i];

	string state[3] = { ".omln", "owln.", "..oLn" };
	for (int i = 0; i < (int)picture[0].size(); i++) {
		string currState = "";
		for (int j = 0; j < 5; j++)
			currState.push_back(picture[j][i]);

		if (currState == state[2])
			continue;
		else {
			int idx = currState == state[0] ? 1 : 0;
			for (int j = 0; j < 5; j++)
				picture[j][i] = state[idx][j];
		}
	}

	for (int i = 0; i < 5; i++)
		cout << picture[i] << '\n';

	return 0;
}