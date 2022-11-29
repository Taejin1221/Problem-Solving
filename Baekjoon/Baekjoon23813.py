# BOJ_23813.py
n = input()
ans = 0
for _ in range(len(n)):
	n = n[1:] + n[0]
	ans += int(n)

print(ans)