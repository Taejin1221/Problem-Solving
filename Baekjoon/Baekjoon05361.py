for _ in range(int(input())):
    a, b, c, d, e = map(int, input().split())
    ans = a * 350.34
    ans += b * 230.90
    ans += c * 190.55
    ans += d * 125.30
    ans += e * 180.90
    
    print(f'${ans:.2f}')
