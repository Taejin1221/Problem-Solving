# Prob10828_Stack.py
class Stack:
	def __init__(self):
		self.__stck = []
		self.__size = 0


	def push(self, data):
		self.__stck.append(data)
		self.__size = self.__size + 1


	def pop(self):
		if self.__stck:
			self.__size = self.__size - 1
			return self.__stck.pop()
		else:
			return -1
			

	def size(self):
		return self.__size


	def empty(self):
		if self.__stck:
			return 0
		else:
			return 1


	def top(self):
		if self.__stck:
			return self.__stck[-1]
		else:
			return -1
			

import sys
def input():
	return sys.stdin.readline()


if (__name__ == '__main__'):
	instNum = int(input().strip())

	stck = Stack()
	for _ in range(instNum):
		inst = input().strip().split()

		if (inst[0] == 'push'):
			stck.push(int(inst[1]))
		elif (inst[0] == 'pop'):
			print(stck.pop())
		elif (inst[0] == 'size'):
			print(stck.size())
		elif (inst[0] == 'empty'):
			print(stck.empty())
		elif (inst[0] == 'top'):
			print(stck.top())
