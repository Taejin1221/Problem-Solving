for _ in range(int(input())):
    n = int(input())
    time, score = 0, 0
    for _ in range(n):
        a, b = input().split()
        a, b = int(a), float(b)
        time += a
        score += a * b
    print(f'{time} {score / time:.1f}')
