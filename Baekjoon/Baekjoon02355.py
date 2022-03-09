def getSum(x):
    return x * (x + 1) // 2

a, b = map(int, input().split())
if a > b:
    a, b = b, a

if (a > 0):
    print(getSum(b) - getSum(a - 1))
elif (a == 0):
    print(getSum(b))
elif (b == 0):
    print(-getSum(-a))
elif (b > 0):
    print(getSum(b) - getSum(-a))
else:
    print(-(getSum(-a) - getSum(-b - 1)))
