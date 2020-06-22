# Baekjoon14888_InsertOperator.py
import sys
input = sys.stdin.readline

N = int( input() )
nums = list( map( int, input().split() ) )
oper = list( map( int, input().split() ) )

# method 1 (572ms)
operators = [ '+' ] * oper[0] + [ '-' ] * oper[1] + [ '*' ] * oper[2] + [ '/' ] * oper[3]

def evaluate( completed ):
	result, idx = nums[0], 1
	for oper in completed:
		oper2 = nums[idx]

		if oper == '+':
			result += oper2
		elif oper == '-':
			result -= oper2
		elif oper == '*':
			result *= oper2
		elif oper == '/':
			if result < 0 and oper2 > 0:
				result = -(-result // oper2)
			else:
				result //= oper2
		
		idx += 1

	return result

from itertools import permutations
completed = list( set( permutations( operators, N - 1 ) ) )
evals = [ evaluate( c ) for c in completed ]

print( max(evals), min(evals), sep = '\n' )


# method 2 (76ms)
def backtrack( prevVal, size, idx, plus, minus, multi, divide ):
	global max, min
	if size == N - 1:
		if max < prevVal:
			max = prevVal
		if min > prevVal:
			min = prevVal
	else:
		if plus:
			backtrack( prevVal + nums[idx], size + 1, idx + 1, plus - 1, minus, multi, divide )

		if minus:
			backtrack( prevVal - nums[idx], size + 1, idx + 1, plus, minus - 1, multi, divide )

		if multi:
			backtrack( prevVal * nums[idx], size + 1, idx + 1, plus, minus, multi - 1, divide )

		if divide:
			if prevVal < 0:
				backtrack( -(abs(prevVal) // nums[idx]), size + 1, idx + 1, plus, minus, multi, divide - 1 )
			else:
				backtrack( prevVal // nums[idx], size + 1, idx + 1, plus, minus, multi, divide - 1 )

max, min = -(10 ** 9 + 1), (10 ** 9 + 1)
backtrack( nums[0], 0, 1, *oper )

print( max, min, sep = '\n' )
