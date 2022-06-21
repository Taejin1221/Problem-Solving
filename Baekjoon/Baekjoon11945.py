n, m = map(int, input().split())
for _ in range(n):
    row = input()
    for i in reversed(row):
        print(i, end = '')
    print('')
