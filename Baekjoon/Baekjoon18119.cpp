// Baekjoon18119_WordMemorization.cpp
// https://www.acmicpc.net/problem/18119

/* Review
 * Date
 01/08 ~ 01/09/2021

 * 잡담
 count 체크하는 부분에서 words[n]이라 써서 자꾸 틀렸다. 이 부분 아니었으면 더 빨리 맞췄을 텐데 ㅂㄷㅂㄷ
 처음 생각한 Solution은 O(26NM)(26을 사실 안붙이는게 맞다)였다. 이건 무조건 TLE. 따라서 Bitmask를 생각했다.
 하지만 Bitmask는 O(NM)이다. 애매했다 사실 5억번 연산이지만 시간제한이 4초라 확신이 없었지만 알고리즘 분류가 Bitmask니까 긴가민가해서 제출했지만 맞았다.
 bit 연산이라 각 쿼리당 속도가 빨라서 가능했던 것 같다.

 * Solution
 처음 생각한 Solution 26 x 10^4(N) x 5 x 10^4(M) = 13 x 10^9(26NM)
 1. 10,000 x 26의 words 2차원 배열을 만들고 각 단어의 알파벳에 해당하는 index('a' -> 0, 'b' -> 1 ...)를 true로 만들어 어떤 알파벳을 가지고 있는지 체크한다.
 2. 26개의 memo 1차원 배열 만들고 쿼리마다 해당하는 알파벳의 index를 true or false로 만들어준다.
 3. 이후 words들 탐색하며 words[i][j] && memo[j]가 false이면 j번째 알파벳을 잊어먹었단 소리니 count를 증가시키지 않는다.

 Bitmask Solution 10^4(N) x 5 x 10^4(M) = 5 x 10^8(NM)
 1. 10,000의 1차원 words 배열을 만든 뒤 각 단어의 알파벳에 해당하는 bit('a' -> 1, 'b' -> 2^1 = 2 ...)를 1로 만들어준다.
 2. memo를 만들어 쿼리마다 해당하는 알파벳의 bit를 toggle(1 -> 0, 0 -> 1) 해준다.
 3. words를 탐색하며 words[i] & memo가 words[i]와 같으면 words[i]의 모든 알파벳들을 memo가 가지고 있단 소리니 count를 증가시킨다.

 * ps
 전에 사실 bitmask 문제를 풀어본적 있지만 그건 답 보고 풀었기 때문에 대충 실루엣만 기억이 났다. 그 이후 처음 혼자의 힘으로 풀어보는 bitmask 문제이다.
 이전까지는 bitmask를 잘 알지 못해서 bitmask 태그만 보면 도망쳤다. 하지만 역시 혼자의 힘으로 푸니 bitmask가 익숙해지고 이전보다 확실히 이해됐다.
 이제 bitmask 태그는 내가 풀 수 있는, 도망치지 않아도 되는 태그가 되었다.
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int words[10'000] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		string str;
		cin >> str;

		for ( char& c : str )
			words[i] |= 1 << (c - 'a');
	}

	int memo = (1 << 26) - 1;
	while ( m-- ) {
		int o; char x;
		cin >> o >> x;

		memo ^= 1 << (x - 'a');

		int count = 0;
		for ( int i = 0; i < n; i++ )
			if ( (memo & words[i]) == words[i] )
				count++;

		cout << count << '\n';
	}

	return 0;
}
