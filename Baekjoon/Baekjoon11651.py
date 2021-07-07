# Baekjoon11651_SortCoordinate2.py
import sys
input = sys.stdin.readline

# method 1
points = []
for _ in range( int( input() ) ):
	x, y = map( int, input().split() )
	points.append( ( y, x ) )

for y, x in sorted( points ):
	print( x, y )

# method 2
points = []
for _ in range( int( input() ) ):
	points.append( tuple( map( int, input().split() ) ) )

def MergeSort( left, right ):
	if left >= right: return
	else:
		mid = ( left + right ) // 2
		MergeSort( left, mid )
		MergeSort( mid + 1, right )
		Merge( left, mid, right )

def Merge( left, mid, right ):
	leftCopy = points[ left : mid + 1 ]
	rightCopy = points[ mid + 1 : right + 1 ]

	lenLeft, lenRight = len( leftCopy ), len( rightCopy )
	idxLeft, idxRight, idxOrigin = 0, 0, left

	while ( ( idxLeft < lenLeft ) and ( idxRight < lenRight ) ):
		leftVal, rightVal = leftCopy[idxLeft], rightCopy[idxRight]

		if leftVal[1] < rightVal[1]:
			points[idxOrigin] = leftVal
			idxLeft += 1
		elif leftVal[1] > rightVal[1]:
			points[idxOrigin] = rightVal
			idxRight += 1
		else:
			if leftVal[0] < rightVal[0]:
				points[idxOrigin] = leftVal
				idxLeft += 1
			else:
				points[idxOrigin] = rightVal
				idxRight += 1

		idxOrigin += 1

	while ( idxLeft < lenLeft ):
		points[idxOrigin] = leftCopy[idxLeft]
		idxOrigin += 1; idxLeft += 1

	while ( idxRight < lenRight ):
		points[idxOrigin] = rightCopy[idxRight]
		idxOrigin += 1; idxRight += 1

MergeSort( 0, len( points ) - 1 )
for x, y in points:
	print( x, y )
