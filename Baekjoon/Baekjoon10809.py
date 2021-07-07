# Baekjoon10809_FindAlphabet.py
S = input()

temp = 'abcdefghijklmnopqrstuvwxyz'
hashtable = { t: -1 for t in temp }

for idx in range( len( S ) ):
	s = S[idx]

	if ( hashtable[s] is -1 ):
		hashtable[s] = idx

for h in hashtable:
	print( hashtable[h], end = ' ' )