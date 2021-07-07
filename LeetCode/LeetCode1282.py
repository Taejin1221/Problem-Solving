# Prob1282_GroupPeople.py
class Solution:
	def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
		groups = []
		info = {}
		appendIndex = 0

		for ID in range(len(groupSizes)):
			groupSize = groupSizes[ID]
			if (groupSizes[ID] not in info):
				info[groupSize] = [appendIndex, 0]
				groups.append([])
				appendIndex = appendIndex + 1

			index = info[groupSize][0]

			groups[index].append(ID)
			info[groupSize][1] = info[groupSize][1] + 1

			if (info[groupSize][1] == groupSize):
				del info[groupSize]

		return groups
