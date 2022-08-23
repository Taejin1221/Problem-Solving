for _ in range(int(input())):
    A, B, C = map(int, input().split())
    ans = 0
    for x in range(1, A + 1):
        for y in range(1, B + 1):
            for z in range(1, C + 1):
                if (x % y) == (y % z) == (z % x):
                    ans += 1
    print(ans)
