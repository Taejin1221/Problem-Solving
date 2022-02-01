nums = []
for _ in range(9):
    a = list(map(int, input().split()))
    nums.append(a)

ans = [0, 0, 0]
for i in range(9):
    for j in range(9):
        if ans[0] < nums[i][j]:
            ans = [nums[i][j], i, j]
print(ans[0])
print(ans[1] + 1, ans[2] + 1)
