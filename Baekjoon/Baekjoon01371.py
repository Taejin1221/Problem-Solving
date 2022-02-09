import sys

diff = ord('a')
alphabets = [ 0 for _ in range(26) ]
for line in sys.stdin.readlines():
    for l in line:
        if (l != ' ' and l != '\n'):
            alphabets[ord(l) - diff] += 1

maxNum = max(alphabets)
for i, a in enumerate(alphabets):
    if (a == maxNum):
        print(chr(diff + i), end = '')
