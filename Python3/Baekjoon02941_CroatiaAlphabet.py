# Baekjoon02941_CroatiaAlphabet.py
cnt, idx = 0, 0
alphabet = [ 'c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=' ]

word = input()

while idx < len(word):
	if ( word[ idx : idx + 3 ] in alphabet ):
		idx = idx + 3
	elif ( word[ idx : idx + 2 ] in alphabet ):
		idx = idx + 2
	else:
		idx = idx + 1
	cnt = cnt + 1

print( cnt )