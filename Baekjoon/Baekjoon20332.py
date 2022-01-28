n = int(input())
scores = list(map(int, input().split()))

if (sum(scores) % 3 == 0):
    print('yes')
else:
    print('no')
