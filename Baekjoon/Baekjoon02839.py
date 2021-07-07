# Baekjoon02839_SugarDelivery.py
n = int(input())

kilo_5 = n // 5
kilo_3 = 0
possible = False

while ( kilo_5 >= 0 ):
	rest = n - ( 5 * kilo_5 )
	if ( rest % 3 == 0 ):
		kilo_3 = rest // 3
		possible = True
		break
	else:
		kilo_5 -= 1

if ( possible ):
	print( kilo_3 + kilo_5 )
else:
	print( -1 )