a, b = map(int, input().split())
c, d = map(int, input().split())
if a + d == c + b:
    if b == d:
        print('Penalty')
    elif b > d:
        print('Esteghlal')
    else:
        print('Persepolis')
elif a + d > c + b:
    print('Persepolis')
else:
    print('Esteghlal')
