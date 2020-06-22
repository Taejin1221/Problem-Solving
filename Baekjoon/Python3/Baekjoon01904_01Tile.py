# Baekjoon01904_01Tile.py
n = int( input() )

tileNum = [ 0, 1, 2 ]

for i in range( 3, n + 1 ):
	tileNum.append( ( tileNum[i - 1] + tileNum[i - 2] ) % 15746 )	

print( tileNum[i] )

# tile1, tile2 = 1, 2
# if n == 1:
# 	print( tile1 )
# elif n == 2:
# 	print( tile2 )
# else:
# 	for i in range( 3, n + 1 ):
# 		tile3 = (tile1 + tile2) % 15746
# 		tile1, tile2 = tile2, tile3

# 	print( tile3 )
