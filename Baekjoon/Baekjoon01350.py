_ = int(input())
files = list(map(int, input().split()))
cluster = int(input())

n = 0
for file in files:
    if (file != 0):
        n += file // cluster + (1 if file % cluster != 0 else 0)
print(n * cluster)
