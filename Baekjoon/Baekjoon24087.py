from math import ceil
s = int(input())
a = int(input())
b = int(input())
print(250 + max(0, int(ceil((s - a) / b))) * 100)
