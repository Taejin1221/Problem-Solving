a, b, c = map(int, input().split())
if a is not b and a is not c:
    print('A')
elif b is not a and b is not c:
    print('B')
elif c is not a and c is not b:
    print('C')
else:
    print('*')
