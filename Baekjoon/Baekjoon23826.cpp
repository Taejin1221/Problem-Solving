// Baekjoon23826.cpp
// https://www.acmicpc.net/problem/23826
#include <iostream>

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

using namespace std;

struct Room {
	int x, y, energy;
	Room(): x(0), y(0), energy(0) { }
	Room(int x, int y, int e): x(x), y(y), energy(e) { }
};

int getDistance(Room a, Room b) {
	return ABS(a.x - b.x) + ABS(a.y - b.y);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Room root;
	cin >> root.x >> root.y >> root.energy;

	Room rooms[1'000];
	for (int i = 0; i < n; i++)
		cin >> rooms[i].x >> rooms[i].y >> rooms[i].energy;

	int maxEnergy = 0;
	for (int i = 0; i < n; i++) {
		int totalInterrupt = 0;
		for (int j = 0; j < n; j++)
			totalInterrupt += max(0, rooms[j].energy - getDistance(rooms[i], rooms[j]));
		maxEnergy = max(maxEnergy, max(0, root.energy - getDistance(root, rooms[i]) - totalInterrupt));
	}

	if (maxEnergy)
		cout << maxEnergy;
	else
		cout << "IMPOSSIBLE";
	cout << '\n';

	return 0;
}