// Baekjoon01300_KthNumber.cpp
// https://www.acmicpc.net/problem/1300

/* Review
 * Date
 01/14/2021

 * Comment
 도저히 생각이 나지 않아서 남들의 Solution을 조금 참조했다. 아직 많이 부족한 것 같다.
 특정 값보다 작은 값들이 몇개 있는지를 알아내는 찾아야하는 건 알았지만, 그걸 어떻게 찾아야하는지를 알지 못했다.

 * Idea
 1. mid보다 작거나 같은 값들은 배열 A의 각 행에 min(mid / i, n)만큼 있다.
 2. 그리고 배열 A에는 같은 숫자가 여러개 있다.
 2-1. 따라서 mid가 k번째로 나오는 수더라도 위의 연산을 수행하면 무조건 k보다 크다.
 2-2. 하지만 mid보다 작은 값들은 무조건 k보다 작다.


 * Solution
 1. [left, right] 범위에서 mid보다 작거나 같은 값들이 몇개 있는지를 구한다.
 2-1. 만약 k보다 크다면 right의 범위를 mid로 땡겨준다.
 (mid - 1로 땡기지 않는 이유는 Idea의 2-1에 의해, mid가 답일 수도 있기 때문이다.)
 2-2. 만약 k보다 작다면 left의 범위를 mid + 1로 땡겨준다.
 (Idea의 2-2에 의해 mid는 답이 아니므로 mid + 1부터 체크한다.)
 3. 만약 left >= right면 그만 둔다.
 4. left가 답이다.
 (일반적인 이진 탐색에선 left가 답이 될 수 없다. 하지만 이 문제는 만약 left와 mid가 같다면(k번째 숫자인 경우) Idea 2-1에 의해 무조건 Solution 2-1이 수행된다.
 따라서 left > right인 경우는 생기지 않고 left == right인 경우만 생긴다. 따라서 left를 출력해도 된다. 물론 right를 출력해도 된다.)

 * Tag
 #Algorithm #BinarySearch

*/

#include <iostream>

using namespace std;

int n, k;

long smallerNumberThan( int a ) {
	long sum = 0l;
	for ( int i = 1; i <= n; i++ )
		sum += min( a / i, n );

	return sum;
}

int main(void) {
	cin >> n >> k;

	int left = 1, right = k;
	while ( left < right ) {
		int mid = ( left + right ) / 2;
		if ( k <= smallerNumberThan( mid ) )
			right = mid;
		else
			left = mid + 1;
	}

	cout << left << '\n';

	return 0;
}