# Baekjoon24510.py
# https://www.acmicpc.net/problem/24510
ans = 0
for _ in range(int(input())):
	line = input()

	currAns = line.count('while') + line.count('for')
	ans = max(ans, currAns)

print(ans)