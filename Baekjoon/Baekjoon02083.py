a, b, c = input().split()
while (a != '#'):
    print(a, end = ' ')
    if (int(b) > 17 or int(c) >= 80):
        print('Senior')
    else:
        print('Junior')
    a, b, c = input().split()
