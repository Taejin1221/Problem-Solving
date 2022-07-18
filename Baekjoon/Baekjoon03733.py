# Baekjoon03733.py
# https://www.acmicpc.net/problem/3733
import sys

lines = sys.stdin.readlines()
for line in lines:
	n, s = map(int, line.split())

	print(s // (n + 1))