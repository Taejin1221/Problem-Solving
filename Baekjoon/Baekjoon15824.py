# Baekjoon15824.py
# https://www.acmicpc.net/problem/15824
import sys
input = sys.stdin.readline

MOD = 1_000_000_007

def pow(x, y):
	if (y == 0):
		return 1
	else:
		half = pow(x, y // 2)

		half = (half * half) % MOD
		if (y % 2):
			half = (half * x) % MOD

		return half

n = int(input())

arr = list(map(int, input().split()))
arr.sort()

prefixSum = [ 0, ]
for i in range(n):
	prefixSum.append((prefixSum[i] + arr[i]) % MOD)

ans = 0
for i in range(n - 1):
	s1 = prefixSum[n] - prefixSum[i + 1]
	s2 = prefixSum[n - i - 1]
	s3 = (s1 - s2) % MOD

	s3 = (s3 * pow(2, i)) % MOD

	ans = (ans + s3) % MOD

print(ans)