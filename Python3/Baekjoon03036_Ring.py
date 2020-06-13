# Baekjoon03036_Ring.py
# https://www.acmicpc.net/problem/3036
from math import gcd
import sys
read = sys.stdin.readline

n = int( read() )
nums = list( map( int, read().split() ) )
for n in nums[1 : ]:
	GCD = gcd( n, nums[0] )
	print( '{}/{}'.format( nums[0] // GCD, n // GCD ) )
