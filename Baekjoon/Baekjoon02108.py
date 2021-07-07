# Baekjoon02108_Statistics.py
import sys
input = sys.stdin.readline

nums, frequency = [], {}
n = int( input() )

avg = 0
for _ in range( n ):
	num = int( input() )
	nums.append( num )
	avg += num

	if num in frequency:
		frequency[num] += 1
	else:
		frequency[num] = 1

nums.sort()
# Arithmetic Mean
print( '{}'.format( round( avg / n ) ) )

# Median Value
print( nums[ n // 2 ] )

# mode
sortedFrequency = sorted( frequency.items(), key = lambda item: item[1], reverse = True )
sortedFrequency = sorted( [ x for x in sortedFrequency if x[1] == sortedFrequency[0][1] ] )
print( sortedFrequency[0][0] if len( sortedFrequency ) == 1 else sortedFrequency[1][0] )

# Range
print( nums[-1] - nums[0] )
