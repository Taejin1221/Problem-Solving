# Baekjoon01193_FindFraction.py
def Sum(n: int) -> int:
	return ( n * (n + 1) // 2 )

X = int( input() )

num = 1
while ( X > Sum(num) ): num += 1

diff = Sum(num) - X
# if num is odd
if ( num % 2 ):
	son = 1 + diff
	mom = num - diff
else:
	son = num - diff
	mom = 1 + diff
	

# son, mom =  (1 + diff, num - diff) if num % 2 else (num - diff, 1 + diff)

print( son, '/', mom, sep = '' )