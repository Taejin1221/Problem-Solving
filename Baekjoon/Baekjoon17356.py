a, b = map(int, input().split())
m = (b - a) / 400
print(f'{1 / (1 + 10 ** m):.4f}')
