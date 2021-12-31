for _ in range(int(input())):
    binary = input()
    
    ans = 0
    for i in range(0, 24):
        if binary[23 - i] == '1':
            ans += 2 ** i
    print(ans)
