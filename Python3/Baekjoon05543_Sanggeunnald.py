# Baekjoon05543_Sanggeunnald.py
minB, minD = 2001, 2001

for _ in range( 3 ):
	temp = int( input() )
	if ( minB > temp ):
		minB = temp

for _ in range( 2 ):
	temp = int( input() )
	if ( minD > temp ):
		minD = temp

print( minB + minD - 50 )
