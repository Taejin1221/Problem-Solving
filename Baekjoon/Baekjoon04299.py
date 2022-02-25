a, b = map(int, input().split())
if a < b or (a + b) % 2 == 1 or (a - b) % 2 == 1:
    print(-1)
else:
    c, d = (a + b) // 2, (a - b) // 2
    print(f'{c} {d}')
