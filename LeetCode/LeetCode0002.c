struct ListNode {
	int val;
	struct ListNode * next;
};

void AddFirst(struct ListNode *target, int data);
void PrintList(struct ListNode *l1);
void FreeList(struct ListNode *l1);
struct ListNode* addTwoNumbers(struct ListNode * l1, struct ListNode * l2);

int main(void) {
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	l1->next = NULL;
	struct ListNode *l2 = malloc(sizeof(struct ListNode));
	l2->next = NULL;

	AddFirst(l1, 3);
	AddFirst(l1, 4);
	AddFirst(l1, 2);

	AddFirst(l2, 4);
	AddFirst(l2, 6);
	AddFirst(l2, 5);
	
	//PrintList(l1);
	//PrintList(l2);

	struct ListNode *result = addTwoNumbers(l1, l2);
	PrintList(result);

	FreeList(l1);
	FreeList(l2);
	FreeList(result);

	return 0;
}

void AddFirst(struct ListNode *target, int data) {
	struct ListNode *temp = malloc(sizeof(struct ListNode));
	temp->val = data;
	temp->next = target->next;
	target->next = temp;
}

void PrintList(struct ListNode *l1) {
	struct ListNode *curr = l1->next;
	while (curr != NULL) {
		printf("%d ", curr->val);
		curr = curr->next;
	} puts(" ");
}

void FreeList(struct ListNode *l1) {
	struct ListNode *curr = l1->next;
	while (curr != NULL) {
		struct ListNode *next = curr->next;
		free(curr);
		curr = next;
	}
	free(l1);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode * result = malloc(sizeof(struct ListNode));
	int carry = 0;

	struct ListNode * curr = result;
	struct ListNode * currl1 = l1;
	struct ListNode * currl2 = l2;

	while (1) {
		int sum = 0;

		if (!currl1) {
			sum = currl2->val + carry;
			currl2 = currl2->next;
		}
		else if (currl2 == NULL) {
			sum = currl1->val + carry;
			currl1 = currl1->next;
		}
		else {
			sum = currl1->val + currl2->val + carry;
			currl1 = currl1->next; currl2 = currl2->next;
		}

		curr->val = sum % 10;
		carry = sum / 10;

		if (currl1 != NULL || currl2 != NULL) {
			curr->next = malloc(sizeof(struct ListNode));
			curr = curr->next;
		}
		else
			break;
	}

	if (carry != 0) {
		curr->next = malloc(sizeof(struct ListNode));
		curr = curr->next;

		curr->val = carry;
	}

	curr->next = NULL;

	return result;
}