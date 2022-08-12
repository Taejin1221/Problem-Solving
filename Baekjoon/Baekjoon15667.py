n = int(input())
for k in range(1, 101):
    if 1 + k + k * k == n:
        print(k)
        break
