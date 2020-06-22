# Baekjoon02920_Scale.py
# https://www.acmicpc.net/problem/2920

scale = list( map( int, input().split() ) )

acs, des = True, True

for i in range( 1, 8 ):
	if scale[i - 1] < scale[i]:
		continue
	else:
		acs = False
		break

for i in range( 1, 8 ):
	if scale[i - 1] > scale[i]:
		continue
	else:
		des = False
		break

if acs:
	print( 'ascending' )
elif des:
	print( 'descending' )
else:
	print( 'mixed' )
