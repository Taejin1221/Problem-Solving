# Prob1753_ShortestPath.py
from math import inf

class PriorityQueue():
	def __init__(self):
		self.queue = [ None, ]
		self.size = 1


	def push(self, data):
		self.queue.append(data)
		self.size = self.size + 1
		me = self.size - 1
		mom = me // 2
		while (me != 1 and self.queue[mom][1] > self.queue[me][1]):
			self.queue[mom], self.queue[me] = self.queue[me], self.queue[mom]
			me = mom
			mom = me // 2


	def pop(self):
		if (self.isEmpty()):
			return None

		last = self.size - 1
		self.queue[1], self.queue[last] = self.queue[last], self.queue[1]

		self.size = self.size - 1

		def Heapify(me):
			leftChild = me * 2
			rightChild = me * 2 + 1

			smaller = None
		
			if (leftChild >= self.size):
				return
			elif (rightChild >= self.size):
				smaller = leftChild
			else:
				if (self.queue[leftChild][1] < self.queue[rightChild][1]):
					smaller = leftChild
				else:
					smaller = rightChild

			if (self.queue[smaller][1] < self.queue[me][1]):
				self.queue[smaller], self.queue[me] = self.queue[me], self.queue[smaller]
				Heapify(smaller)

		Heapify(1)

		return self.queue.pop()
		

	def isEmpty(self) -> 'bool':
		if self.size > 1: return False
		else: return True


	def PrintQueue(self):
		print(self.queue)


class Graph():
	VISIT = 1
	UNVISIT = 0
	V = 0
	W = 1

	def __init__(self, vertexSize):
		self.adjList = { vertex:[] for vertex in range(1, vertexSize + 1) }
		self.vertexSize = vertexSize


	def InsertEdge(self, vertex, adjVertex, weight):
		self.adjList[vertex].append((adjVertex, weight))
		self.adjList[vertex].sort()

	def PrintGraph(self):
		for curr in self.adjList:
			print('V({}) = {}'.format(curr, self.adjList[curr]))


	def DijkstraAlgorithm_Array(self, start):
		visited = { vertex: Graph.UNVISIT \
		for vertex in range(1, self.vertexSize + 1) }
		shortestPath = { vertex: inf \
		for vertex in range(1, self.vertexSize + 1) }

		visited[start], shortestPath[start] = Graph.VISIT, 0
		for i in range(self.vertexSize - 1):
			minPath = None
			for currVertex in self.adjList:
				if (visited[currVertex] is Graph.VISIT):
					for adjVertex in self.adjList[currVertex]:
						adjVertexNum = adjVertex[Graph.V]
						if (visited[adjVertexNum] is Graph.UNVISIT):
							tempWeight = shortestPath[currVertex] + adjVertex[Graph.W]
							if (shortestPath[adjVertexNum] > tempWeight):
								shortestPath[adjVertexNum] = tempWeight
								
							if ((minPath is None) or \
								(shortestPath[minPath] > shortestPath[adjVertexNum])):
								minPath = adjVertexNum
			if (minPath is not None):
				visited[minPath] = Graph.VISIT

		for short in shortestPath:
			if shortestPath[short] is not inf:
				print(shortestPath[short])
			else:
				print('INF')


	def DijkstraAlgorithm(self, start):
		visited = { vertex: Graph.UNVISIT for vertex in range(1, self.vertexSize + 1) }
		shortestPath = { vertex: inf for vertex in range(1, self.vertexSize + 1) }
		queue = PriorityQueue()

		adjList = self.adjList

		visited[start], shortestPath[start] = Graph.VISIT, 0
		prevVertex = start

		while (prevVertex is start or not queue.isEmpty()):
			for adjVertex in adjList[prevVertex]:
				adjVertexNum = adjVertex[Graph.V]
				tempWeight = shortestPath[prevVertex] + adjVertex[Graph.W]

				if (visited[adjVertexNum] is Graph.UNVISIT):
					queue.push((adjVertexNum, tempWeight))

			nextVertex = queue.pop()
			while (nextVertex and visited[nextVertex[Graph.V]] is Graph.VISIT):
				nextVertex = queue.pop()

			if (nextVertex is not None):
				nextVertexNum = nextVertex[Graph.V]

				shortestPath[nextVertexNum] = nextVertex[Graph.W]
				visited[nextVertexNum] = Graph.VISIT

				prevVertex = nextVertex[Graph.V]

		for short in shortestPath:
			if shortestPath[short] is not inf:
				print(shortestPath[short])
			else:
				print('INF')


if (__name__ == '__main__'):
	# vertexSize, edgeSize = map(int, input().split())
	# start = int(input())

	# myGraph = Graph(vertexSize)

	# for _ in range(edgeSize):
	# 	u, v, w = map(int, input().split())
	# 	myGraph.InsertEdge(u, v, w)

	# myGraph.DijkstraAlgorithm(start)

	# myGraph.PrintGraph()

	myGraph = Graph(5)
	myGraph.InsertEdge(5, 1, 1)
	myGraph.InsertEdge(1, 2, 2)
	myGraph.InsertEdge(1, 3, 3)
	myGraph.InsertEdge(2, 3, 4)
	myGraph.InsertEdge(2, 4, 5)
	myGraph.InsertEdge(3, 4, 6)
	myGraph.DijkstraAlgorithm(1)	