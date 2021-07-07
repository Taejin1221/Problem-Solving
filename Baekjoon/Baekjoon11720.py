# Baekjoon11720_SumOfNumbers.py
n = int( input() )
numbers = input( )

sum = 0

for idx in range( n ):
	sum += int( numbers[idx] )

print( sum )