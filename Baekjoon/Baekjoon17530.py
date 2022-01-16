votes = []
for _ in range(int(input())):
    votes.append(int(input()))

if votes[0] == max(votes):
    print('S')
else:
    print('N')
