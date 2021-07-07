# Baekjoon01427_Sortinside.py
num = input()
digits = list(num)
digits.sort( reverse = True )
print( ''.join( digits ) )