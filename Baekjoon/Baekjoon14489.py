# Baekjoon14489.py
# https://www.acmicpc.net/problem/14489
a, b = map(int, input().split())
c = int(input())

money, chicken = a + b, c * 2
print(money if money < chicken else money - chicken)
