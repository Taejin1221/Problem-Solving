a, b, c, d = map(int, input().split())
men = map(int, input().split())

for p in men:
    ans = 0
    rest = p % (a + b)
    if rest != 0 and rest <= a:
        ans += 1

    rest = p % (c + d)
    if rest != 0 and rest <= c:
        ans += 1
    
    print(ans)
