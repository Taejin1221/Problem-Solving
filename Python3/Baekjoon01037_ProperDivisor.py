# Baekjoon01037_ProperDivisor.py
# https://www.acmicpc.net/problem/1037

n = int( input() )
divisors = list( sorted( map( int, input().split() ) ) )

print( divisors[0] * divisors[-1] )
