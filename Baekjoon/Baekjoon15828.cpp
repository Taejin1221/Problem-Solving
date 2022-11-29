// BOJ_15828.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	queue<int> buffer;

	int input;
	cin >> input;

	while (input != -1) {
		if (input == 0) {
			buffer.pop();
		}
		else {
			if (n > buffer.size())
				buffer.push(input);
		}
		cin >> input;
	}

	if (buffer.size() != 0) {
		while (!buffer.empty()) {
			cout << buffer.front() << ' ';
			buffer.pop();
		}
	} else
		cout << "empty";
	cout << '\n';

	return 0;
}