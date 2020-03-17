# Baekjoon01436_MovieDirectorShom.py
n = int( input() )
count = 0

for i in range( 666, 2700000 ):
	stri = str( i )
	if '666' in stri:
		count += 1

	if count == n:
		print( stri )
		break
