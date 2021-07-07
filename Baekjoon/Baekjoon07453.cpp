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

 * p.s.
 1/14에 재체점 되었더니 지금까지의 모든 Solution이 시간초과가 떴다. 그래서 다시 풀었다.
 기존엔 일단 a + b를 배열에 저장하였었다. 그 부분을 지우고 c + d배열을 이진 탐색할 때 더한 값을 찾는 식으로 바꿨다.
 기존의 코드는 lower_bound와 upper_bound를 모두 처음부터 끝까지 구하였다. 하지만 사실 upper_bound는 lower부터 end까지만 구하면 되지 않겠는가.
 그래서 그렇게 고쳤더니 맞았다. 굉장히 까다롭고 좋은 문제였다.
 다른 사람들의 코드를 보니 정렬을 할 때 radix sort를 하였다. 정말 똑똑한 사람들인 것 같다. 그러면 32 * n이니 시간이 많이 줄 것 같다.
*/

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator vii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a[4'000], b[4'000], c[4'000], d[4'000];
	for ( int i = 0; i < n; i++ )
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int idx = 0;
	vector<int> table ( n * n );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			table[idx++] = c[i] + d[j];

	sort( table.begin(), table.end() );

	long ans = 0l;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			int value = -(a[i] + b[j]);
			vii lower = lower_bound( table.begin(), table.end(), value );
			vii upper = upper_bound( lower, table.end(), value );

			ans += upper - lower;
		}
	}

	cout << ans << '\n';

	return 0;
}