# Baekjoon10814_SortAgeorder.py
import sys

people = []
for _ in range( int( input() ) ):
	age, name = sys.stdin.readline().rstrip().split()
	people.append( ( int( age ), name ) )

people.sort( key = lambda x: x[0] )
for age, name in people:
	print( age, name )
