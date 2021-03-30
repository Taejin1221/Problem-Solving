// Programmers42579_BestAlbum.cpp
// https://programmers.co.kr/learn/courses/30/lessons/42579
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Genre {
	string genre;
	int playSum;
	Genre( string s, int playSum ): genre( s ), playSum( playSum ) { }
	bool operator<( const Genre& n2 ) const {
		return playSum > n2.playSum;
	}
};

struct Song {
	int songNumber, playNumber;
	Song( int sn, int pn ): songNumber( sn ), playNumber( pn ) { }
	bool operator<( const Song& s2 ) const {
		if ( playNumber != s2.playNumber )
			return playNumber > s2.playNumber;
		else
			return songNumber < s2.songNumber;
	}
};

vector<int> solution( vector<string> genres, vector<int> plays ) {
	int n = genres.size();
	vector<int> ans;

	map<string, int> sums;
	map<string, vector<Song>> genreList;
	for ( int i = 0; i < n; i++ ) {
		if ( genreList.find( genres[i] ) == genreList.end() ) {
			genreList.insert( make_pair( genres[i], vector<Song> () ) );
			sums.insert( make_pair( genres[i], 0 ) );
		}
		genreList[genres[i]].push_back( Song( i, plays[i] ) );
		sums[genres[i]] += plays[i];
	}

	vector<Genre> genre_sort;
	for ( map<string, int>::iterator iter = sums.begin(); iter != sums.end(); ++iter )
		genre_sort.push_back( Genre( iter->first, iter->second ) );
	sort( genre_sort.begin(), genre_sort.end() );

	for ( Genre& node : genre_sort ) {
		string& genre = node.genre;
		vector<Song>& genreSongs = genreList[genre];
		sort( genreSongs.begin(), genreSongs.end() );

		ans.push_back( genreSongs[0].songNumber );
		if ( genreSongs.size() > 1 )
			ans.push_back( genreSongs[1].songNumber );
	}

	return ans;	
}