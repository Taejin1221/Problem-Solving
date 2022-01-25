// Baekjoon22939.cpp
// https://www.acmicpc.net/problem/22939
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

#define X first
#define Y second
#define ABS(x) ((x) > 0 ? x : -(x))

using namespace std;

using pii = pair<int, int>;

pii start, target;

int getMinDistnace(vector<pii>& topping) {
	vector<int> distances;
	int currXDistance = ABS(start.X - topping[0].X) + ABS(topping[0].X - topping[1].X) + ABS(topping[1].X - topping[2].X) + ABS(topping[2].X - target.X);
	int currYDistance = ABS(start.Y - topping[0].Y) + ABS(topping[0].Y - topping[1].Y) + ABS(topping[1].Y - topping[2].Y) + ABS(topping[2].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	currXDistance = ABS(start.X - topping[0].X) + ABS(topping[0].X - topping[2].X) + ABS(topping[2].X - topping[1].X) + ABS(topping[1].X - target.X);
	currYDistance = ABS(start.Y - topping[0].Y) + ABS(topping[0].Y - topping[2].Y) + ABS(topping[2].Y - topping[1].Y) + ABS(topping[1].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	currXDistance = ABS(start.X - topping[1].X) + ABS(topping[1].X - topping[0].X) + ABS(topping[0].X - topping[2].X) + ABS(topping[2].X - target.X);
	currYDistance = ABS(start.Y - topping[1].Y) + ABS(topping[1].Y - topping[0].Y) + ABS(topping[0].Y - topping[2].Y) + ABS(topping[2].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	currXDistance = ABS(start.X - topping[1].X) + ABS(topping[1].X - topping[2].X) + ABS(topping[2].X - topping[0].X) + ABS(topping[0].X - target.X);
	currYDistance = ABS(start.Y - topping[1].Y) + ABS(topping[1].Y - topping[2].Y) + ABS(topping[2].Y - topping[0].Y) + ABS(topping[0].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	currXDistance = ABS(start.X - topping[2].X) + ABS(topping[2].X - topping[0].X) + ABS(topping[0].X - topping[1].X) + ABS(topping[1].X - target.X);
	currYDistance = ABS(start.Y - topping[2].Y) + ABS(topping[2].Y - topping[0].Y) + ABS(topping[0].Y - topping[1].Y) + ABS(topping[1].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	currXDistance = ABS(start.X - topping[2].X) + ABS(topping[2].X - topping[1].X) + ABS(topping[1].X - topping[0].X) + ABS(topping[0].X - target.X);
	currYDistance = ABS(start.Y - topping[2].Y) + ABS(topping[2].Y - topping[1].Y) + ABS(topping[1].Y - topping[0].Y) + ABS(topping[0].Y - target.Y);
	distances.push_back(currXDistance + currYDistance);

	return *min_element(distances.begin(), distances.end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char line[101];

	// Jelly, Chocolate, Berry, Walnut
	vector<pii> toppings[4];

	for (int i = 0; i < n; i++) {
		cin >> line;

		for (int j = 0; j < n; j++) {
			if (line[j] == 'H')
				start = { i, j };
			else if (line[j] == '#')
				target = { i, j };
			else if (line[j] == 'J')
				toppings[0].push_back({ i, j });
			else if (line[j] == 'C')
				toppings[1].push_back({ i, j });
			else if (line[j] == 'B')
				toppings[2].push_back({ i, j });
			else if (line[j] == 'W')
				toppings[3].push_back({ i, j });
		}
	}

	int distances[4] = { getMinDistnace(toppings[0]), getMinDistnace(toppings[1]), getMinDistnace(toppings[2]), getMinDistnace(toppings[3]) };
	pair<string, int> ans = { "Assassin", distances[0] };

	if (ans.second > distances[1])
		ans = { "Healer", distances[1] };

	if (ans.second > distances[2])
		ans = { "Mage", distances[2] };

	if (ans.second > distances[3])
		ans = { "Tanker", distances[3] };

	cout << ans.first << '\n';

	return 0;
}