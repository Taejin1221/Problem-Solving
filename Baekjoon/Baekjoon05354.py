for _ in range(int(input())):
    n = int(input())
    print('#' * n)
    for _ in range(n - 2):
        print('#', 'J' * (n - 2), '#', sep = '')
    if n > 1:
        print('#' * n)
    print('')
