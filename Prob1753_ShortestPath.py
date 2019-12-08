# Prob1753_ShortestPath.py
import sys
from heapq import heappush, heappop

def input():
	return sys.stdin.readline()

class Graph():
	VISIT = 1
	UNVISIT = 0

	def __init__(self, vertexSize):
		self.adjList = { vertex:[] for vertex in range(1, vertexSize + 1) }
		self.vertexSize = vertexSize


	def InsertEdge(self, vertex, adjVertex, weight):
		self.adjList[vertex].append((adjVertex, weight))


	def PrintGraph(self):
		for curr in self.adjList:
			print('V({}) = {}'.format(curr, self.adjList[curr]))


	def DijkstraAlgorithm(self, start):
		visited = { vertex: Graph.UNVISIT for vertex in range(1, self.vertexSize + 1) }
		shortest = { vertex: -1 for vertex in range(1, self.vertexSize + 1) }
		queue = []

		heappush(queue, (0, start))
		while (queue):
			prevWeight, prevVertex = heappop(queue)

			if (visited[prevVertex] is Graph.VISIT):
				continue

			shortest[prevVertex] = prevWeight
			visited[prevVertex] = Graph.VISIT

			for adjVertex, adjWeight in self.adjList[prevVertex]:
				if (visited[adjVertex] is Graph.UNVISIT):
					heappush(queue, (prevWeight + adjWeight, adjVertex))

		for short in shortest:
			if shortest[short] is -1:
				print('INF')
			else:
				print(shortest[short])


if (__name__ == '__main__'):
	vertexSize, edgeSize = map(int, input().strip().split())
	start = int(input())

	myGraph = Graph(vertexSize)

	for _ in range(edgeSize):
		u, v, w = map(int, input().strip().split())
		myGraph.InsertEdge(u, v, w)

	myGraph.DijkstraAlgorithm(start)
