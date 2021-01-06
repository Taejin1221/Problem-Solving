// Baekjoon17298_Ribignum.cpp
// https://www.acmicpc.net/problem/17298

/*
Review
 * Date
 01/07/2021

 * 문제
 단계별로 풀어보기 Stack 6번 문제

 * Solution
 Stack에 { 값, 인덱스 }를 저장한다. 한번 순환하면서 arr[i]보다 작은 숫자들을 Stack에서 빼주며 ribig에 넣어준다.
 arr[i]보다 크면 멈춘다. arr[i]보다 큰 숫자가 나오면 그 이전은 위의 작업에 의해 큰 숫자보다 큰 숫자들만 들어간다.
 따라서 모두 뺴준 뒤 Stack에 남은 숫자들은 모두 arr[i]들 보다 커지며, 그럼 지금 넣으려는 수는 오큰수가 아니게 된다.
 또한 왼쪽에서 오른쪽으로 순환하기에 arr[i]은 Stack에 들어있는 수보다 오른쪽에 있는 숫자이고, arr[i]보다 작은 숫자면 말 그대로 arr[i]가 그 숫자의 오큰수가 된다.

 * idea
 Stack 카테고리에서 봐서 Stack으로 바로 생각하고 풀었다.
*/

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int ribig[1'000'000];
	fill( ribig, ribig + n, -1 );

	vector<pair<int, int> > stck;
	for ( int i = 0; i < n; i++ ) {
		while ( !stck.empty() && stck.back().first < arr[i] ) {
			pair<int, int> temp = stck.back(); stck.pop_back();
			ribig[temp.second] = arr[i];
		}

		stck.push_back( { arr[i], i } );
	}

	for ( int i = 0; i < n; i++ )
		cout << ribig[i] << ' ';
	cout << '\n';

	return 0;
}
