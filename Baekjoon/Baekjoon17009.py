a3 = int(input())
a2 = int(input())
a1 = int(input())

b3 = int(input())
b2 = int(input())
b1 = int(input())

scoreA = a3 * 3 + a2 * 2 + a1
scoreB = b3 * 3 + b2 * 2 + b1
if (scoreA > scoreB):
    print('A')
elif (scoreA < scoreB):
    print('B')
else:
    print('T')
