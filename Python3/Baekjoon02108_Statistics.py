# Baekjoon02108_Statistics.py
import sys
input = sys.stdin.readline

nums = []
n = int( input() )

avg = 0
for _ in range( n ):
	num = int( input() )
	nums.append( num )
	avg += num

nums.sort()
print( '{:.1f}'.format( avg / n ) )
print( nums[ n // 2 ] )
print( )
print( nums[-1] - nums[0] )