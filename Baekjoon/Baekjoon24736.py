info1 = list(map(int, input().split()))
info2 = list(map(int, input().split()))
aScore = info1[0] * 6 + info1[1] * 3 + info1[2] * 2 + info1[3] * 1 + info1[4] * 2
bScore = info2[0] * 6 + info2[1] * 3 + info2[2] * 2 + info2[3] * 1 + info2[4] * 2
print(aScore, bScore)
