# LeetCode0290_WordPattern.py
# https://leetcode.com/problems/word-pattern/
class Solution:
	def wordPattern( self, pattern: str, s: str ) -> bool:
		tokens = s.split();

		if ( len( tokens ) != len( pattern ) ):
			return False;

		table1, table2 = { }, { };
		for i in range( len( pattern ) ):
			currPattern = pattern[i]
			if ( (currPattern in table1) ):
				if ( ( table1[currPattern] != tokens[i] ) ):
					return False;
			else:
				if ( tokens[i] in table2 ):
					return False;
				else:
					table1[currPattern] = tokens[i];
					table2[tokens[i]] = currPattern;

		return True;
