// Prob4963_CountIslands.c
#include <stdio.h>
#include <stdlib.h> /* malloc(), free() */

/* ========== Define ========== */
#define VISIT 1
#define UNVISIT 0

typedef struct _Position {
	int row;
	int col;
} Position;

typedef struct _ListNode {
	Position val;
	struct _ListNode * next;
} ListNode, * ListNodePtr;

typedef struct _QueueList {
	ListNodePtr front;
	ListNodePtr rear;
} QueueList, * QueueListPtr;

void InitQueue(QueueListPtr queue);
int isEmpty(QueueListPtr queue);
void Enqueue(QueueListPtr queue, Position val);
Position Dequeue(QueueListPtr queue);
void BFS(char map[][50], char visited[][50], int width, int height, int row, int col);
int CountIslands(char map[][50], int width, int col);
/* ============================ */

int main(void) {
	int width, height;
	char map[50][50];

	scanf("%d", &width); scanf("%d", &height); getchar();
	while (width != 0 && height != 0) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				scanf("%c", &map[i][j]);
		}
		printf("%d\n", CountIslands(map, width, height));

		scanf("%d", &width); scanf("%d", &height); getchar();
	}

	return 0;
}

void InitQueue(QueueListPtr queue) {
	queue->front = queue->rear = NULL;
}

int isEmpty(QueueListPtr queue) {
	return (queue->front == NULL);
}

void Enqueue(QueueListPtr queue, Position val) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;

	if (isEmpty(queue))
		queue->front = queue->rear = newNode;
	else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

Position Dequeue(QueueListPtr queue) {
	Position rtrnVal = queue->front->val;
	ListNodePtr rmNode = queue->front;

	queue->front = queue->front->next;

	free(rmNode);

	return rtrnVal;
}

void BFS(char map[][50], char visited[][50], int width, int height, int row, int col) {
	QueueList queue;
	InitQueue(&queue);

	Position startPosition = { row, col };
	Enqueue(&queue, startPosition);

	while (! isEmpty(&queue)) {
		Position currVertex = Dequeue(&queue);

		Position surr[3] = {
			{currVertex.row, currVertex.col + 1}, // right position of currVertex
			{currVertex.row + 1, currVertex.col}, // bottom position of currVertex
			{currVertex.row + 1, currVertex.col + 1} // diagnal position of currVertex
		};

		for (int i = 0; i < 3; i++) {
			int adjRow = surr[i].row;
			int adjCol = surr[i].col;
			if ((adjRow < width) && (adjCol < height))
				if ((map[adjRow][adjCol] == 1) && (visited[adjRow][adjCol] == UNVISIT)) {
					visited[adjRow][adjCol] = VISIT;
					Enqueue(&queue, surr[i]);
				}
		}
	}
}

int CountIslands(char map[][50], int width, int height) {
	char visited[50][50] = { UNVISIT, };
	int numIsland = 0;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			// if unvisit
			if (! visited[i][j]) {
				visited[i][j] = VISIT;
				if (map[i][j]) {
					BFS(map, visited, width, height, i, j);
					numIsland++;
				}
			}

	return numIsland;
}