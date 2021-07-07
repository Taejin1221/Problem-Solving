# Baekjoon02775_IWillBeQueen.py
for _ in range( int( input() ) ):
	floor = int( input() )
	ho = int( input() ) - 1
	
	table = [ [ 1 ] for i in range( floor + 1 ) ]
	for i in range( 1, ho + 1 ):
		table[0].append( i + 1 )

	for f in range( 1, floor + 1 ):
		for h in range( 1, ho + 1 ):
			table[f].append( sum( table[f - 1][ : h + 1 ] ) )
	print( table[floor][ho] )
