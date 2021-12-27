digit10 = '9780921418'

startAns = 0
for i in range(len(digit10)):
    startAns += int(digit10[i]) * (3 if i % 2 else 1)

a = int(input())
startAns += a

a = int(input())
startAns += a * 3

a = int(input())
startAns += a

print(f'The 1-3-sum is {startAns}')
