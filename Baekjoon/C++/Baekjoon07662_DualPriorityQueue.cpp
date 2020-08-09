// Baekjoon07662_DualPriorityQueue.cpp
// https://www.acmicpc.net/problem/7662
#include <iostream>
#include <set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int k;
		cin >> k;

		multiset<int> dpq;
		while ( k-- ) {
			char opr; int x;
			cin >> opr >> x;

			if ( opr == 'I' )
				dpq.insert( x );
			else {
				if ( dpq.empty() )
					continue;

				if ( x == -1 )
					dpq.erase( dpq.begin() );
				else
					dpq.erase( dpq.find( *(dpq.rbegin()) ) );
			}
		}

		if ( dpq.empty() )
			cout << "EMPTY\n";
		else
			cout << *(dpq.rbegin()) << ' ' << *(dpq.begin()) << '\n';
	}

	return 0;
}