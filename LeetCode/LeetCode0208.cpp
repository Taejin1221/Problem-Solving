// LeetCode0208_ImplementTrie.cpp
// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
	bool isEnd;
	Trie* dict[26];

	Trie() {
		isEnd = false;
		for ( int i = 0; i < 26; i++ )
			dict[i] = NULL;
	}

	void insert( string word ) {
		if ( !word.size() )
			isEnd = true;
		else {
			int next = word[0] - 'a';
			if ( dict[next] == NULL )
				dict[next] = new Trie( );
			dict[next]->insert( string( word.begin() + 1, word.end() ) );
		}
	}

	bool search( string word ) {
		if ( !word.size() )
			return isEnd;
		else {
			int next = word[0] - 'a';
			if ( dict[next] )
				return dict[next]->search( string( word.begin() + 1, word.end() ) );
			else
				return false;
		}
	}

	bool startsWith( string prefix ) {
		if ( !prefix.size() )
			return true;
		else {
			int next = prefix[0] - 'a';
			if ( dict[next] )
				return dict[next]->startsWith( string( prefix.begin() + 1, prefix.end() ) );
			else
				return false;
		}
	}
};