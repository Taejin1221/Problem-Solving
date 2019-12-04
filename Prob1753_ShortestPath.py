# Prob1753_ShortestPath.py
class Graph():
	VISIT = 1
	UNVISIT = 0
	vertex = 0
	weight = 1

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
		visited = { vertex: Graph.UNVISIT for vertex in range(1, self.vertexSize + 1) }
		shortestPath = { vertex: inf for vertex in range(1, self.vertexSize + 1) }

if (__name__ == '__main__'):
	vertexSize, edgeSize = map(int, input().split())
	start = int(input())

	myGraph = Graph(vertexSize)

	for _ in range(edgeSize):
		u, v, w = map(int, input().split())
		myGraph.InsertEdge(u, v, w)

	# myGraph.PrintGraph()