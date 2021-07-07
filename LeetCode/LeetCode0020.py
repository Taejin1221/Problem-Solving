# LeetCode0020_ValidParentheses.py
class Solution:
	def isValid( self, s: str) -> bool:
		valid = True
		stack = []

		for bracket in s:
			if ( bracket is '(' ):
				stack.append( 0 )
			elif ( bracket is '{' ):
				stack.append( 1 )
			elif ( bracket is '[' ):
				stack.append( 2 )

			elif ( bracket is ')' ):
				if len(stack):
					paren = stack.pop()
					if ( paren is not 0 ):
						valid = False
						break
				else:
					valid = False
					break
			elif ( bracket is '}' ):
				if len(stack):
					paren = stack.pop()
					if ( paren is not 1 ):
						valid = False
						break
				else:
					valid = False
					break
			elif( bracket is ']' ):
				if len(stack):
					paren = stack.pop()
					if ( paren is not 2 ):
						valid = False
						break
				else:
					valid = False
					break

		if len(stack):
			return False
		else:
			return valid
