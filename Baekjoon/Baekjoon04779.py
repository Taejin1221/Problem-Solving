# Baekjoon04779.py
# https://www.acmicpc.net/problem/4779
cantorSet = [ '-' ]
for _ in range(1, 13):
	cantorSet.append(cantorSet[-1] + ' ' * len(cantorSet[-1]) + cantorSet[-1])

import sys

nums = sys.stdin.readlines()
for num in nums:
	n = int(num.rstrip())

	print(cantorSet[n])