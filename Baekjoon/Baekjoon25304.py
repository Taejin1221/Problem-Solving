priceSum = int(input())
ans = 0
for _ in range(int(input())):
    p, n = map(int, input().split())
    ans += p * n
print("Yes" if ans == priceSum else "No")
