a, b, c = map(int, input().split())
row = a // c + (1 if a % c != 0 else 0)
col = b // c + (1 if b % c != 0 else 0)
print(row * col)
