# Baekjoon02164_Card2.py
n = int( input( ) )
cards = [ i for i in range( 1, n + 1 ) ]

front, rear = 0, n - 1
while ( rear - front > 0 ):
	front += 1
	cards.append( cards[front] )
	front += 1
	rear += 1

print( cards[rear] )
