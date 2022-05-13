p1, q1, p2, q2 = map(int, input().split())
area = p1 * p2 / (q1 * q2)
print(1 if p1 * p2 % (q1 * q2) == 0 and area % 2 == 0 else 0)
