#include <stdio.h>
#include <stdlib.h>
#include "../DataStructure/List/List.h"

ListNodePtr removeNthFromEnd(ListNodePtr head, int n) {
	static int check = 0;
	if (! head) {
		return head;
	} else {
		head->next = removeNthFromEnd(head->next, n);
		check++;
		if (check == n) {
			ListNodePtr remove = head;
			head = head->next;
			free(remove);

			return head;
		}

		return head;
	}
}

int main(int argc, char* argv[]) {
	ListNodePtr head = NULL;
	for (int i = 1; i < argc-1; i++) {
		head = InsertNode_Last(head, CreateData(atoi(argv[i])));
	}
	PrintList(head);

	head = removeNthFromEnd(head, atoi(argv[argc-1]));
	PrintList(head);

	return 0;
}
