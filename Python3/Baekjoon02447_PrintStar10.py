# Baekjoon02447_PrintStar10.py
def Block( size, rowStart, rowEnd ):
	if ( size == 3 ):
		stars[rowStart] += '***'
		stars[rowStart + 1] += '* *'
		stars[rowEnd] += '***'
	else:
		unit = size // 3
		for _ in range( 3 ):
			Block( unit, rowStart, rowStart + unit - 1 ) # top
			Block( unit, rowStart + 2 * unit, rowStart + size - 1 ) # bottom

		Block( unit, rowStart + unit, rowStart + 2 * unit - 1 )
		for idx in range( rowStart + unit, rowStart + 2 * unit ):
			stars[idx] += ' ' * unit
		Block( unit, rowStart + unit, rowStart + 2 * unit - 1 )
		



n = int( input() )
stars = [ '' for _ in range( n ) ]
Block( n, 0, n - 1 )
for s in stars:
	print( s )