// Baekjoon11723_Set.cpp
// https://www.acmicpc.net/problem/11723
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct MySet {
	bool table[21];
	MySet();
	void add( int x );
	void remove( int x );
	int check( int x );
	void toggle( int x );
	void all();
	void empty();
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	MySet set;
	while ( n-- ) {
		string temp;
		cin >> temp;

		if ( temp[0] == 'a' && temp[1] == 'd' ) {
			int x;
			cin >> x;

			set.add(x);
		}
		else if ( temp[0] == 'r' ) {
			int x;
			cin >> x;

			set.remove(x);
		}
		else if ( temp[0] == 'c') {
			int x;
			cin >> x;

			cout << set.check(x) << '\n';
		}
		else if ( temp[0] == 't' ) {
			int x;
			cin >> x;

			set.toggle(x);
		}
		else if ( temp[0] == 'a' )
			set.all();
		else if ( temp[0] == 'e' )
			set.empty();
	}

	return 0;
}

MySet::MySet() {
	fill( table, table + 21, false );
}

void MySet::add( int x ) {
	table[x] = true;
}

void MySet::remove( int x ) {
	table[x] = false;
}

int MySet::check( int x ) {
	return ( table[x] );
}

void MySet::toggle( int x ) {
	table[x] ^= 1;
}

void MySet::all() {
	fill( table, table + 21, true );
}

void MySet::empty() {
	fill( table, table + 21, false );
}
