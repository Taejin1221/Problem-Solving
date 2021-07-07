// LeetCode0211_AddAndSearchWord.cpp
// https://leetcode.com/problems/add-and-search-word-data-structure-design/
// August Leetcoding Challenge Day 5
class WordDictionary {
	bool search_helper( const string& word, int idx ) {
		if ( idx == word.size() )
			return isEnd;
		else {
			if ( word[idx] == '.' ) {
				for ( int i = 0; i < 26; i++ )
					if ( dict[i] && dict[i]->search_helper( word, idx + 1 ) )
						return true;
				return false;
			} else {
				int next = word[idx] - 'a';
				if ( dict[next] )
					return dict[next]->search_helper( word, idx + 1 );
				else
					return false;
			}
		}
	}

public:
	bool isEnd;
	WordDictionary* dict[26];

	WordDictionary() {
		isEnd = false;
		for ( int i = 0; i < 26; i++ )
			dict[i] = NULL;
	}

	void addWord( string word ) {
		if ( !word.size() )
			isEnd = true;
		else {
			int next = word[0] - 'a';
			if ( dict[next] == NULL )
				dict[next] = new WordDictionary();
			dict[next]->addWord( string( word.begin() + 1, word.end() ) );
		}
	}


	bool search( string word ) {
		return search_helper( word, 0 );
	}
};