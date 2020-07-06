// Baekjoon04358_Ecology.cpp
// https://www.acmicpc.net/problem/4358
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

class Trie {
public:
	int count;
	bool end;
	map<char, Trie*> m;

	Trie();
	~Trie();
	void Insert( const string& str );
	bool Find( const string& str );
	int getCount( const string& str );
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision( 4 );

	int num = 0;
	string str;
	set<string> s;
	Trie* trie = new Trie();
	while ( getline(cin, str) ) {
		if ( !trie->Find( str ) ) {
			trie->Insert( str );
			s.insert( str );
		}
		num++;
	}

	set<string>::iterator iter;
	for ( iter = s.begin(); iter != s.end(); ++iter) {
		int count = trie->getCount( *iter );
		 cout << *iter << ' ' << (float)count / num * 100 << '\n';
	}

	return 0;
}

Trie::Trie( ) {
	this->end = false;
	this->count = 1;
}

Trie::~Trie( ) {
	this->m.clear();
}

void Trie::Insert( const string& str ) {
	if ( str.size() == 0 )
		this->end = true;
	else{
		char next = str[0];
		if ( m[next] == NULL )
			this->m[next] = new Trie();
		m[next]->Insert( string( str.begin() + 1, str.end() ) );
	}
}

bool Trie::Find( const string& str ) {
	if ( str.size() ) {
		char next = str[0];
		if ( m[next] == NULL )
			return false;
		else
			return m[next]->Find( string( str.begin() + 1, str.end() ) );
	} else {
		if ( this->end )
			this->count++;
		return this->end;
	}
}

int Trie::getCount( const string& str ) {
	if ( str.size() )
		return m[str[0]]->getCount( string( str.begin() + 1, str.end() ) );
	else
		return this->count;
}