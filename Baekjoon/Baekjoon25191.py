chicken = int(input())
coke, beer = map(int, input().split())
print(min(chicken, coke // 2 + beer))
