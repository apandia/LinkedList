#include <iostream>

using namespace std;

//Simple program to create a linked list and print the data values

class SingleLinkedListNode {
public:
	int data;
	SingleLinkedListNode* next;

	SingleLinkedListNode(int nodeData) {
		data = nodeData;
		next = nullptr;
	}
};

class SingleLinkList {
public:
	SingleLinkedListNode* head;
	SingleLinkedListNode* tail;

	SingleLinkList() {
		head = nullptr;
		tail = nullptr;
	}

	void insertNewNode(int data) {
		SingleLinkedListNode* newNode = new SingleLinkedListNode(data);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}

		tail = newNode;
	}

	void printLinkedList() {
		SingleLinkedListNode* current = head;

		while(current) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << endl;
	}
};

void printLinkedListReverse(SingleLinkedListNode* head) 
{
	if (head == nullptr)
		return;

	printLinkedListReverse(head->next);
	cout << head->data << " ";
}

//Driver function
int main()
{
	SingleLinkList* list = new SingleLinkList;

	list->insertNewNode(10);
	list->insertNewNode(20);
	list->insertNewNode(30);
	list->insertNewNode(40);
	list->insertNewNode(50);
	list->insertNewNode(60);

	cout << "Linked list in inser order: ";
	list->printLinkedList();

	cout << "Linked list in reverse: ";
	printLinkedListReverse(list->head);

	return 0;
}