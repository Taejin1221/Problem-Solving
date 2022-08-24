n = int(input())
nums = list(map(int, input().split()))

ans = 0
for i in range(n):
    if nums[i] != i + 1:
        ans += 1
print(ans)
