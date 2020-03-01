# Baekjoon03009_FourthSpot.py
xs, ys = {}, {}
for _ in range( 3 ):
	x, y = map( int, input().split() )
	if x not in xs:
		xs[x] = 1
	else:
		xs[x] += 1

	if y not in ys:
		ys[y] = 1
	else:
		ys[y] += 1

print( min(xs, key = lambda x: xs[x] ), min(ys, key = lambda x: ys[x] ) )
