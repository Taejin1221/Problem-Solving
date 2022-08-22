n = int(input())
ans = False
for i in range(0, 31):
    if 2 ** i == n:
        ans = True
print(1 if ans else 0)
