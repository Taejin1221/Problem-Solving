// Baekjoon22232.cpp
// https://www.acmicpc.net/problem/22232
#include <iostream>

#include <set>
#include <string>
#include <algorithm>

using namespace std;

// { string, string }을 담는 pair
/*
struct pss {
	string first, second;
};
라고 생각
*/
typedef pair<string, string> pss;

// extension을 담는 집합
set<string> extensionTable;

// 비교 함수
bool compare(const pss& s1, const pss& s2) {
	// s1의 FILENAME과 s2의 FILENAME이 같다면
	if (s1.first.compare(s2.first) == 0) {
		auto ex1 = extensionTable.find(s1.second), ex2 = extensionTable.find(s2.second);
		auto end = extensionTable.end();

		// s1, s2의 EXTENSION이 집합에 둘 다 있거나, 둘다 없으면
		if ((ex1 == end && ex2 == end) || (ex1 != end && ex2 != end))
			return (s1.second).compare(s2.second) < 0; // EXTENSION의 사전 순으로
		else if (ex1 != end) // s1의 EXTENSION이 집합에 있고, s2의 EXTENSION이 집합에 없다면
			return true; // s1이 먼저
		else
			return false; // s2가 먼저
	}
	else
		return s1.first.compare(s2.first) < 0; // FILENAME의 사전순으로 정렬
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// 파일들을 담는 배열, { FILENAME, EXTENSION } 으로 pair로 저장
	pss arr[200'000];
	for (int i = 0; i < n; i++) {
		string fileName;
		cin >> fileName;

		// fileName을 .을 기준으로 자르는 코드
		int nameIdx = 0, flag = 0;
		char names[2][11] = { 0, };
		for (char& c : fileName) {
			if (c == '.') {
				flag = 1;
				nameIdx = 0;
				continue;
			}

			names[flag][nameIdx++] = c;
		}

		// names[0]은 . 앞의 문장(FILENAME)이, names[1]은 . 뒤의 문장(EXTENSION)이 저장
		arr[i].first = string(names[0]);
		arr[i].second = string(names[1]);
	}

	// EXTENSION을 집합에 삽입
	for (int i = 0; i < m; i++) {
		string extension;
		cin >> extension;

		extensionTable.insert(extension);
	}

	// 정렬
	sort(arr, arr + n, compare);

	// 출력
	for (int i = 0; i < n; i++)
		cout << arr[i].first << '.' << arr[i].second << '\n';

	return 0;
}