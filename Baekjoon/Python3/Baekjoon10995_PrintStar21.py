# Baekjoon10995_PrintStar21.py
N = int( input() )

for _ in range( N ):
	for i in range( N ):
		if i % 2 == 0:
			print( '*', end = '' )
		else:
			print( ' ', end = '' )
	print( '' )

	for i in range( N ):
		if i % 2 == 0:
			print( ' ', end = '' )
		else:
			print( '*', end = '' )
	print( '' )
