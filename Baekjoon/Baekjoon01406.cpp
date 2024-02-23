// Baekjoon01406.cpp
// https://www.acmicpc.net/problem/1406
#include <iostream>

using namespace std;

struct Node {
	char character;
	Node* next, * prev;

	Node(char c, Node* n, Node* p): character(c), next(n), prev(p) { }
};

class LinkedList {
	Node* head;
	Node* curr;
	Node* tailNode;

public:
	LinkedList(string str) {
		head = new Node(str[0], NULL, NULL);

		Node* prev = head;
		for (int i = 1; i < str.size(); i++) {
			prev->next = new Node(str[i], NULL, prev);
			prev = prev->next;
		}

		prev->next = new Node('\0', NULL, prev);
		prev = prev->next;

		curr = prev;
		tailNode = prev;
	}

	~LinkedList() {
		Node* temp = head;
		while (temp != NULL) {
			Node* temp2 = temp->next;
			delete temp;

			temp = temp2;
		}
	}

	void moveLeft() {
		if (curr != head)
			curr = curr->prev;
	}

	void moveRight() {
		if (curr != tailNode)
			curr = curr->next;
	}

	void deleteCharacter() {
		if (curr->prev == head) {
			Node* temp = head;

			head = curr;
			curr->prev = NULL;

			delete temp;
		} else if (curr != head) {
			Node* temp = curr->prev;
			curr->prev->prev->next = curr;
			curr->prev = curr->prev->prev;
	
			delete temp;
		}
	}

	void insertCharacter(char alphabet) {
		Node* newNode = new Node(alphabet, curr, curr->prev);
		if (curr == head) {
			head = newNode;
			curr->prev = newNode;
		} else {
			curr->prev->next = newNode;
			curr->prev = newNode;
		}
	}

	char getCursor() {
		if (curr != tailNode)
			return curr->character;
		else
			return '-';
	}

	string getString() {
		string result = "";

		Node* temp = head;
		while (temp != tailNode) {
			result.push_back(temp->character);
			temp = temp->next;
		}
		

		return result;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	LinkedList list = LinkedList(s);

	int t;
	cin >> t;
	while (t--) {
		char opr;
		cin >> opr;

		if (opr == 'L') {
			// cout << "Before move left, cursor : " << list.getCursor() << endl;
			list.moveLeft();
			// cout << "After move left, cursor : " << list.getCursor() << endl;
		} else if (opr == 'D') {
			// cout << "Before move right, cursor : " << list.getCursor() << endl;
			list.moveRight();
			// cout << "After move right, cursor : " << list.getCursor() << endl;
		} else if (opr == 'B') {
			// cout << "Delete character, current : " << list.getString() << ", cursor : " << list.getCursor() << endl;
			list.deleteCharacter();
			// cout << list.getString() << '\n';
		} else {
			char temp;
			cin >> temp;

			// cout << "Insert character, current : " << list.getString() << endl;
			list.insertCharacter(temp);
			// cout << list.getString() << '\n';
		}
		// cout << "==============================\n";
	}

	cout << list.getString() << '\n';

	return 0;
}