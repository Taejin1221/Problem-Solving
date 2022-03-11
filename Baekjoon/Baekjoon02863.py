a, b = map(int, input().split())
c, d = map(int, input().split())
ans = [a / c + b / d, 0]
rot1 = c / d + a / b
if rot1 > ans[0]:
    ans = [rot1, 1]
rot2 = d / b + c / a
if rot2 > ans[0]:
    ans = [rot2, 2]
rot3 = b / a + d / c
if rot3 > ans[0]:
    ans = [rot3, 3]
print(ans[1])
