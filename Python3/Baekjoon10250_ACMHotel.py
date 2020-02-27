# Baekjoon10250_ACMHotel.py
for _ in range( int(input() ) ):
	H, W, N = map( int, input().split() )

	floorNum = (N % H) if (N % H) is not 0 else H
	houseNum = (N - 1) // H + 1

	print( 
		str( floorNum ) + ( '0' + str( houseNum ) if houseNum < 10 else str ( houseNum ) )
		)