n, w, h = map(int, input().split())
for i in range(n):
    a = int(input())
    if a**2 <= w**2+h**2:
        print('DA')
    else:
        print('NE')
