# Baekjoon01316_GroupWordChecker.py
def isGroupWord( word : str ) -> bool:
	chars = []
	idx = 0

	while ( idx < len(word) ):
		w = word[idx]
		if w in chars:
			return False
		else:
			chars.append( w )
			idx = idx + 1
			while ( idx < len(word) and w == word[idx] ):
				idx = idx + 1

	return True

cnt = 0

time = int( input() )
for _ in range( time ):
	word = input()
	if ( isGroupWord( word ) ):
		cnt = cnt + 1

print( cnt )