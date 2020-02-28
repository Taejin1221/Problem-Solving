# Baekjoon_02869_SnailWantsToClimb.py
from math import ceil

A, B, V = map( int, input().split() )
print( ceil( ( V - A ) / ( A - B ) ) + 1 )