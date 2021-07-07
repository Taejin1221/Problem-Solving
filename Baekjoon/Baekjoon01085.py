# Baekjoon01085_EscapeFromRectangle.py
x, y, w, h = map( int, input().split() )
dist = [ x, y, w - x, h - y ]
print( min( dist ) )