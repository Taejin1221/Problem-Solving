# Baekjoon07568_BigBody.py
n = int( input() )

people = []
for _ in range( n ):
	person = tuple( map( int, input().split() ) )
	people.append( person )

for idx in range( n ):
	rate = 0
	me = people[idx]
	for enemy in people:
		if ( ( enemy[0] > me[0] ) and ( enemy[1] > me[1] ) ):
			rate += 1
	print( rate + 1, end = ' ' )
print( '' )