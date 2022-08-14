l, r, a = map(int, input().split())
if l < r:
    m = min(a, r - l)
    l += m
    a -= m
else:
    m = min(a, l - r)
    r += m
    a -= m
l += a // 2
r += a // 2
print(min(l, r) * 2)
