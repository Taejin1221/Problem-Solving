# Baekjoon11729_HanoiTower.py
route = []
def Hanoi( n: int, curr = 1, target = 3, temp = 2 ) -> None:
	if ( n == 1 ):
		route.append( ( curr, target ) )
	else:
		Hanoi( n - 1, curr, temp, target)
		route.append( ( curr, target ) )
		Hanoi( n - 1, temp, target, curr )


n = int( input() )
Hanoi( n )

print( len( route ) )
for a, b in route:
	print( a, b )
