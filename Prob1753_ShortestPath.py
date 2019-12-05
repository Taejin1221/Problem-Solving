# Prob1753_ShortestPath.py
from math import inf

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

	def DijkstraAlgorithm(self, start):
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
						tempWeight = shortestPath[currVertex] + adjVertex[Graph.W]
						if (shortestPath[adjVertex[Graph.V]] > tempWeight):
							shortestPath[adjVertex[Graph.V]] = tempWeight
							
						if ((minPath is None) or \
							(shortestPath[minPath] > shortestPath[adjVertex[Graph.V]])):
							minPath = shortestPath[adjVertex[Graph.V]]
			visited[minPath] = Graph.VISIT

		for short in shortestPath:
			print(short)

if (__name__ == '__main__'):
	vertexSize, edgeSize = map(int, input().split())
	start = int(input())

	myGraph = Graph(vertexSize)

	for _ in range(edgeSize):
		u, v, w = map(int, input().split())
		myGraph.InsertEdge(u, v, w)

	myGraph.DijkstraAlgorithm(start)

	# myGraph.PrintGraph()