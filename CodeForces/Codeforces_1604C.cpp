// Codeforces_1604C.cpp
#include <iostream>

using namespace std;

class ListNode {
public:
	int value; ListNode* next;
	ListNode(int v, ListNode* next): value(v), next(next) { }
};

void solveTestCase() {
	ListNode* head;

	int n;
	cin >> n;

	int arr[100'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	head = new ListNode(arr[n - 1], nullptr);
	ListNode* curr = head;
	for (int i = 2; i <= n; i++) {
		curr->next = new ListNode(arr[n - i], nullptr);
		curr = curr->next;
	}

	int size = n;
	while (size > 0) {
		int i;
		ListNode* curr, *prev = nullptr;
		for (i = size, curr = head; i > 0 && (curr->value % (i + 1) == 0); prev = curr, curr = curr->next, i--);

		if (i == 0)
			break;

		if (prev == nullptr)
			head = curr->next;
		else
			prev->next = curr->next;
		size--;

		delete curr;
	}

	if (size) {
		cout << "NO";
		for (ListNode* curr = head; curr != nullptr; ) {
			ListNode* temp = curr->next;
			delete curr;

			curr = temp;
		}
	}
	else
		cout << "YES";
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
