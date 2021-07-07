# LeetCode0017_LetterCombinationsOfAPhoneNumber.py
class Solution:
	phone = {
		'2' : [ 'a', 'b', 'c' ],
		'3' : [ 'd', 'e', 'f' ],
		'4' : [ 'g', 'h', 'i' ],
		'5' : [ 'j', 'k', 'l' ],
		'6' : [ 'm', 'n', 'o' ],
		'7' : [ 'p', 'q', 'r', 's' ],
		'8' : [ 't', 'u', 'v' ],
		'9' : [ 'w', 'x', 'y', 'z' ]
	}

	def letterCombinations( self, digits: str ) -> List[str]:
		rtrn = []

		def helper( prevStr, idx ):
			if ( idx == len( digits ) ):
				rtrn.append( prevStr )
				return
			else:
				for p in self.phone[ digits[idx] ]:
					helper( prevStr + p, idx + 1)

		if digits is not '':
			helper( '', 0 )

		return rtrn
