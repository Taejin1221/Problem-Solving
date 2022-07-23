n = int(input())
a = int(input())
while (a != 0):
    if (n != 0 and a % n == 0):
        print(f'{a} is a multiple of {n}.')
    else:
        print(f'{a} is NOT a multiple of {n}.')
    a = int(input())
