for _ in range(int(input())):
    yonsei, korea = 0, 0
    for _ in range(9):
        a, b = map(int, input().split())
        yonsei += a
        korea += b
    if yonsei > korea:
        print("Yonsei")
    elif korea > yonsei:
        print("Korea")
    else:
        print("Draw")
