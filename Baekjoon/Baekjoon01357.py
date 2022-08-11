# Baekjoon01357.py
# https://www.acmicpc.net/problem/1357
a, b = input().split()
a = int((''.join(reversed(a))))
b = int((''.join(reversed(b))))
c = (''.join(reversed(str(a+b))))
print(int(c))