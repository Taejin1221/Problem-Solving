# InputMaker.py
import os, sys

os.chdir(sys.argv[1])

n = sys.argv[2]
start = int(sys.argv[3])
end = int(sys.argv[4])

with open('input', 'wt') as f:
	f.write(n + '\n')
	for i in range(start, end + 1):
		f.write(f'{i} ')