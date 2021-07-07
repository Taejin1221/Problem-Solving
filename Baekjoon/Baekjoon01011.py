# Baekjoon01011_FlyMeToTheAlphaCentauri.py
S = lambda n: n * (n + 1)
def Travel(dist: int) -> int:
	n = 1
	while ( S(n) < dist ):
		n += 1

	if ( dist - S(n - 1) <= n ):
		return (2 * n - 1)
	else:
		return (2 * n)

for _ in range( int( input() ) ):
	x, y = map( int, input().split() )
	print( Travel( y - x ) )
