n = int(input())
costs = list(map(int, input().split()))
print(sum(costs) - max(costs))
