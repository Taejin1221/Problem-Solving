y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())
yeon = man = y2 - y1
if (m1 > m2) or (m1 == m2 and d1 > d2):
    man -= 1
se = yeon + 1

print(man)
print(se)
print(yeon)
