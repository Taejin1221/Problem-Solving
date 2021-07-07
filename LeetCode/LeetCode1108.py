# LeetCode1108_DefangingAnIPAddress.py
class Solution:
	def defangIPaddr(self, address: str) -> str:
		temp = address.split('.')
		return '[.]'.join(temp)