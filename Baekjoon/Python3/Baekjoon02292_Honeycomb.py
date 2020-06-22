# Baekjoon02292_Honeycomb.py
N = int( input() )

an_1, n = 1, 1
while ( N > an_1 ):
	n = n + 1
	an_1 = an_1 + 6 * ( n - 1 )

print( n )