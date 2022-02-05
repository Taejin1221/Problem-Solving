# Baekjoon02386.py
# https://www.acmicpc.net/problem/2386
while True:
	string = input()
	if (string == '#'):
		break
	alpha, string = string[0], string[2:]
	print(alpha, string.lower().count(alpha))