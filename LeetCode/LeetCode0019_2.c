#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/List/List.h"

int lenList(ListNodePtr head) {
    int len = 0;
    for (ListNodePtr p = head; p; p = p->next)
        len++;
    
    return len;
}

struct _ListNode* removeNthFromEnd(struct _ListNode* head, int n) {
    int len = lenList(head);
    
    ListNodePtr temp = head;    
    ListNodePtr prev;
    
    for (int i = 0; i < len - n; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    ListNode * removed;
    if (temp == head) {
        removed = head;
        head = removed->next;
    } else {
        removed = temp;
        prev->next = removed->next;
    }
    free(removed);
    
    return head;
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