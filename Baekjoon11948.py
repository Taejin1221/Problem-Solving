science, society = [], []
for _ in range(4):
    science.append(int(input()))
for _ in range(2):
    society.append(int(input()))

science.sort(reverse = True)
society.sort(reverse = True)

print(sum(science[:3]) + society[0])
