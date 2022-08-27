for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = 0
    nums = map(int, input().split())
    for i in nums:
        ans += i // k
    print(ans)
