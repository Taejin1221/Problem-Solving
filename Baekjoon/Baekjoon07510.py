# Baekjoon07510.py
# https://www.acmicpc.net/problem/7510
for i in range(int(input())):
	a, b, c = map(int, input().split())

	print(f'Scenario #{i + 1}:')
	if (max(a, b, c) ** 2 == a ** 2 + b ** 2 + c ** 2 - max(a, b, c) ** 2):
		print('yes')
	else:
		print('no')
	print('')