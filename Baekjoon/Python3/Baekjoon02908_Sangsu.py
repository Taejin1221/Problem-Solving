# Baekjoon02908_Sangsu.py
import sys

A, B = sys.stdin.readline().split()

A = A[::-1]
B = B[::-1]

print( A if A > B else B )