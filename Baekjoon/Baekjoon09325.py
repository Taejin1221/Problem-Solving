for _ in range(int(input())):
    ans = int(input())
    for _ in range(int(input())):
        a, b = map(int, input().split())
        ans += a * b
    print(ans)
