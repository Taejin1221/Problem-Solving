# Baekjoon15829_Hashing.py
# https://www.acmicpc.net/problem/15829
l = int( input() )
string = input()

r = 31
m = 1234567891

hashValue = 0
for i, s in enumerate(string):
	hashValue += ((ord( s ) - 96) * (r ** i))
	hashValue %= m

print( hashValue )
