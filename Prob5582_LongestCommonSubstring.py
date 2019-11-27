# Prob5582_LongestCommonSubstring.py
str1 = input()
str2 = input()
# str1 = 'ABRACADABRA'
# str2 = 'ECADADABRBCRDARA'

str1Size = len(str1)
str2Size = len(str2)

def LogestCommonSubstring() -> int:
	table = [ [0 for i in range(str2Size)] for j in range(str1Size)]
	max1 = 0

	for i in range(str1Size):
		for j in range(str2Size):
			if ((i is 0) or (j is 0)):
				table[i][j] = 0
			elif (str1[i - 1] is str2[j - 1]):
				table[i][j] = table[i - 1][j - 1] + 1

				if (max1 < table[i][j]):
					max1 = table[i][j]
			else:
				table[i][j] = 0

	return max1

rtrnVal = LogestCommonSubstring()

print(rtrnVal)