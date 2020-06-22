# Baekjoon02446_PrintStar9.py
N = int( input() )

for i in range( N ):
	print( ' ' * i + '*' * ( ( N - i ) * 2 - 1 ) )

for i in range( N - 2, -1, -1 ):
	print( ' ' * i + '*' * ( ( N - i ) * 2 - 1 ) )	