// Baekjoon07453_Sum0FourNumber.cpp
// https://www.acmicpc.net/problem/7453

/* Review
 * Date
 01/11/2021

 * Comment
 단순할 것 같았지만 굉장히 까다로운 문제였다. 처음엔 c + d의 값들을 map에 넣어 찾았지만 시간 초과였다. 그래서 그 다음으론 set에 넣어 찾았지만 이번에도 시간 초과였다.
 그래서 마지막으로 lower_bound, upper_bound로 구현하였더니 드디어 맞았다. 사실 이전엔 lower_bound, upper_bound를 사용한적이 거의 없어 잘 몰랐었다.
 하지만 이번 문제를 풀음으로써 lower_bound에 대한 자신감이 생겼다.

 * Solution
 특정 value와 더했을 때 0이 되는 값은 -value이다. 따라서 이 문제는 a와 b의 모든 더하기 경우의 수를 구하고, c와 d의 모든 더하기 경우를 구한 뒤,
 a+b의 value가 c+d에 -value로 들어있으면 count를 증가시키면된다. 이때 단순 탐색으로 구현하면 O(n^2)으로 결국 O(n^2 * n^2)이다.
 그러므로 정렬한 뒤 이진탐색으로 값을 찾아주면 정렬과 탐색은 O(n^2 * log n^2)이다.
 1. a + b와 c + d를 구한다.
 2. c + d를 정렬한다.
 3. a + b 배열에 있는 값들에 -를 곱한 값을 c + d에 이진 탐색으로 찾아준다.
*/

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int tableSize = n * n;

	int a[4'000], b[4'000], c[4'000], d[4'000];
	for ( int i = 0; i < n; i++ )
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int idx1 = 0;
	vector<int> table1 ( tableSize );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			table1[idx1++] = a[i] + b[j];

	int idx2 = 0;
	vector<int> table2 ( tableSize );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			table2[idx2++] = c[i] + d[j];

	sort( table2.begin(), table2.end() );

	long ans = 0l;
	for ( int i = 0; i < tableSize; i++ ) {
		int value = -table1[i];
		int upper = upper_bound( table2.begin(), table2.end(), value ) - table2.begin();
		int lower = lower_bound( table2.begin(), table2.end(), value ) - table2.begin();

		ans += upper - lower;
	}

	cout << ans << '\n';

	return 0;
}