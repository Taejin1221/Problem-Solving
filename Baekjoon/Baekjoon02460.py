ans, prev = 0, 0
for _ in range(10):
    a, b = map(int, input().split())
    
    prev = prev - a + b

    ans = max(ans, prev)

print(ans)
