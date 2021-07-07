// LeetCode1079_LetterTilePossibilities.cpp
// https://leetcode.com/problems/letter-tile-possibilities/
class Solution {
private:
	void backtracking( string& tiles, string curr, set<string>& sequences, vector<bool>& isUsed ) {
		if ( curr.size() == tiles.size() )
			return;
		else {
			string newString;
			for ( int i = 0; i < tiles.size(); i++ ) {
				if ( !isUsed[i] ) {
					isUsed[i] = true;

					newString = curr + tiles[i];
					sequences.insert( newString );
					backtracking( tiles, newString, sequences, isUsed );

					isUsed[i] = false;
				}
			}
		}
	}
public:
	int numTilePossibilities( string tiles ) {
		set<string> sequences;
		vector<bool> isUsed ( tiles.size() );

		backtracking( tiles, "", sequences, isUsed );

		return sequences.size();
	}
};