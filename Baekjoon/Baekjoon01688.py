trophies = [int(input()) for _ in range(int(input()))]

for _ in range(2):
    ans = 1
    see = trophies[0]
    for t in trophies[1:]:
        if see < t:
            ans +=1
            see = t
    print(ans)
    trophies.reverse()
