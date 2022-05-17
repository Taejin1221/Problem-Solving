area, p1 = map(int, input().split())
radius, p2 = map(int, input().split())
per1 = area / p1
per2 = radius ** 2 * 3.14159265359 / p2
print('Whole pizza' if per1 < per2 else 'Slice of pizza')
