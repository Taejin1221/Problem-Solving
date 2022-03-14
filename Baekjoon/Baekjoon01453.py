_ = input()
wants = list(map(int, input().split()))

seat = [ False for _ in range(101) ]
ans = 0
for want in wants:
    if seat[want]:
        ans += 1
    else:
        seat[want] = True

print(ans)
