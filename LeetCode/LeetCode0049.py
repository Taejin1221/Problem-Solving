# LeetCode0049_GroupAnagrams.py
class Solution:
	def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
		rtrnDic = {}
		for s in strs:
			key = str(sorted(s))
			if key in rtrnDic:
				rtrnDic[key].append( s )
			else:
				rtrnDic[key] = [ s ]

		return rtrnDic.values()
