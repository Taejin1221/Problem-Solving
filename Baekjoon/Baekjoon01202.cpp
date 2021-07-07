// Baekjoon01202_JewelryThief.cpp
// https://www.acmicpc.net/problem/1202
#include <algorithm> /* sort() */
#include <iostream>
#include <queue> /* priority_queue */

using namespace std;

struct Jewelry {
	int weight;
	int price;
	Jewelry(int w, int p): weight(w), price(p) {};
	Jewelry(): weight(0), price(0) {};
};

bool compare(const Jewelry& j1, const Jewelry& j2 ) {
	if ( j1.weight != j2.weight )
		return j1.weight < j2.weight;
	else
		return j1.price < j2.price;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int jewelNum, bagNum;
	cin >> jewelNum >> bagNum;

	Jewelry jewels[300000];
	for ( int i = 0; i < jewelNum; i++ )
		cin >> jewels[i].weight >> jewels[i].price;

	int bags[300000];
	for ( int i = 0; i < bagNum; i++ )
		cin >> bags[i];
	sort( jewels, jewels + jewelNum, compare );
	sort( bags, bags + bagNum );

	int jewelIdx = 0;
	long totalPrice = 0l;
	priority_queue<int> pq;
	for ( int i = 0; i < bagNum; i++ ) {
		while ( jewelIdx < jewelNum && jewels[jewelIdx].weight <= bags[i] )
			pq.push( jewels[jewelIdx++].price );

		if ( !pq.empty() ) {
			totalPrice += pq.top();
			pq.pop();
		}
	}

	cout << totalPrice << '\n';

	return 0;
}