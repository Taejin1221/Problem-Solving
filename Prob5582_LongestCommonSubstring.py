# Prob5582_LongestCommonSubstring.py
str1 = input()
str2 = input()
# str1 = 'ABRACADABRA'
# str2 = 'ECADADABRBCRDARA'

def LogestCommonSubstring() -> int:
	table = []
	max1 = 0

	for i in range(len(str1)):
		table.append([])
		for j in range(len(str2)):
			if ((i is 0) or (j is 0) or not(str1[i - 1] is str2[j - 1])):
				table[i].append(0)
			else:
				table[i].append(table[i - 1][j - 1] + 1)
				max1 = max(max1, table[i][j])

	return max1

rtrnVal = LogestCommonSubstring()

print(rtrnVal)