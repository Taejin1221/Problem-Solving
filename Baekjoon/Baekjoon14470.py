a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

isFrozen = False
ans = 0
if a < 0:
    ans += min(b - a, -a) * c
    isFrozen = True
    a = min(0, b)

if a == 0 and isFrozen:
    ans += d

if a != b:
    ans += (b - a) * e

print(ans)
