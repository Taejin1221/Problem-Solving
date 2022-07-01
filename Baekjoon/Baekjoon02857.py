# Baekjoon02857.py
# https://www.acmicpc.net/problem/2857
ans = []
for i in range(1, 6):
	spy = input()
	if "FBI" in spy:
		ans.append(i)

if ans:
	for a in ans:
		print(a, end = ' ')
	print('')
else:
	print("HE GOT AWAY!")
