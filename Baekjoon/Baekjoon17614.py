n = int(input())
ans = 0
for i in range(1, n + 1):
    n_str = str(i)
    for s in n_str:
        if s in '369':
            ans += 1
print(ans)
