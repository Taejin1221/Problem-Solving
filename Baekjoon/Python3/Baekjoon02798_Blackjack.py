# Baekjoon02798_Blackjack.py
n, m = map( int, input().split() )

cards = list( map( int, input().split() ) )
cards.reverse()

def helper():
	winVal = 0
	for i in range( n - 2 ):
		for j in range( i + 1, n - 1 ):
			for k in range( j + 1, n ):
				sumCards = cards[i] + cards[j] + cards[k]
				if ( sumCards == m ):
					return sumCards
				elif ( sumCards < m ):
					if ( winVal < sumCards):
						winVal = sumCards

	return winVal

print( helper() )
