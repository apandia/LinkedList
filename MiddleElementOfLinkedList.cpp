#include <iostream>

using namespace std;

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

	SingleLinkList() {
		head = nullptr;
	}
};

//Insert new node at tail
void insertNodeAtTail(SingleLinkedListNode** head, int data)
{
	SingleLinkedListNode* newNode = new SingleLinkedListNode(data);

	if (*head == nullptr) {
		*head = newNode;
		return;
	}

	SingleLinkedListNode* temp = *head;

	//Move till the last node
	while (temp->next) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void printLinkedList(SingleLinkedListNode* head)
{
	SingleLinkedListNode* current = head;

	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

int getMiddleElement(SingleLinkedListNode* head)
{
	if (head == nullptr)
		return -1;

	SingleLinkedListNode* slow = head;
	SingleLinkedListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;
}

//Driver function
int main()
{
	SingleLinkList* list = new SingleLinkList;

	insertNodeAtTail(&list->head, 10);
	insertNodeAtTail(&list->head, 20);
	insertNodeAtTail(&list->head, 30);
	insertNodeAtTail(&list->head, 40);
	insertNodeAtTail(&list->head, 50);
	insertNodeAtTail(&list->head, 60);

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	cout << "Middle Element of Linked List = " << getMiddleElement(list->head) << endl;

	return 0;
}