# Baekjoon11051_BinomialCoefficient.py
# https://www.acmicpc.net/problem/11051
n, k = map( int, input().split() )

if k < n // 2:
	k = n - k

son, mom = 1, 1
for i in range( k + 1, n + 1 ):
	son *= i

for i in range( 2, (n - k) + 1 ):
	mom *= i

print( (son // mom) % 10007 )
