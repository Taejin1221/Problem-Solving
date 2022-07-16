# Baekjoon02547.py
# https://www.acmicpc.net/problem/2547
for _ in range(int(input())):
	input()
	n = int(input())
	if (n == 0):
		print("NO")
	else:
		sum1 = 0
		for _ in range(n):
			sum1 += int(input())

		print("YES" if sum1 % n == 0 else "NO")
