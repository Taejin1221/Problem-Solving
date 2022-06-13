n, m = map(int, input().split())
A = []
for _ in range(n):
    A.append(list(map(int, input().split())))

B = []
for _ in range(n):
    B.append(list(map(int, input().split())))

for (rowA, rowB) in zip(A, B):
    for (a, b) in zip(rowA, rowB):
        print(a + b, end = ' ')
    print()
