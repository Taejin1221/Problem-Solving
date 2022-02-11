# Baekjoon01769.py
# https://www.acmicpc.net/problem/1769
x = input()

ans = 0
x_int, x_string = int(x), x
while (x_int > 9):
	x_int = 0
	for i in x_string:
		x_int += int(i)

	x_string = str(x_int)

	ans += 1

print(ans)
print("NO" if x_int % 3 else "YES")