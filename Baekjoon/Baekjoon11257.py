# Baekjoon11257.py
# https://www.acmicpc.net/problem/11257
passScore = [35 * 0.3, 25 * 0.3, 40 * 0.3]

for _ in range(int(input())):
	info = list(map(int, input().split()))
	studentNumber, scores = info[0], info[1:]

	isPass = [i <= j for (i, j) in zip(passScore, scores)]
	print(studentNumber, sum(scores), 'FAIL' if (False in isPass or sum(scores) < 55) else 'PASS')
