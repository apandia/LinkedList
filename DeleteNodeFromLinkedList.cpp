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

//Delete node at tail
void deleteNodeAtTail(SingleLinkedListNode** head)
{
	if ((*head) == nullptr)
		return;

	SingleLinkedListNode* temp = *head;
	SingleLinkedListNode* prev = *head;

	//Move till the last node
	while (temp->next) {
		prev = temp;
		temp = temp->next;
	}

	//prev will be new last node. set the next pointer to null
	prev->next = nullptr;

	cout << "\nDeleting node at tail with value: " << temp->data;
	delete temp;
	temp = nullptr;
}

//Delete node at start
void deleteNodeAtStart(SingleLinkedListNode** head)
{
	if ((*head) == nullptr)
		return;

	SingleLinkedListNode* temp = *head;

	(*head) = temp->next;

	cout << "\nDeleting node at start with value: " << temp->data;
	delete temp;
	temp = nullptr;
}

//Delete node at given position
void deleteNodeAtPosition(SingleLinkedListNode** head, int position)
{
	if (*head == nullptr)
		return;

	if (position == 0) {
		SingleLinkedListNode* temp = *head;

		*head = temp->next;

		cout << "\nDeleting node at start with value: " << temp->data;
		delete temp;
		temp = nullptr;
		return;
	}

	SingleLinkedListNode* temp = *head;
	int currentPos = 0;

	//Iterate till previous value for given position value
	while (temp) {
		if (currentPos == (position - 1))
			break;

		temp = temp->next;
		currentPos++;
	}

	//the node to delete is the next node of temp
	SingleLinkedListNode* node = temp->next;

	//make the temp node point to next node of node to delete
	temp->next = node->next;

	cout << "\nDeleting node at start with value: " << node->data;
	delete node;
	node = nullptr;
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
	insertNodeAtTail(&list->head, 70);
	insertNodeAtTail(&list->head, 80);
	insertNodeAtTail(&list->head, 90);

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	
	deleteNodeAtStart(&list->head);
	deleteNodeAtStart(&list->head);	

	cout << "\nLinked List After deleting 2 nodes at start: ";
	printLinkedList(list->head);

	deleteNodeAtTail(&list->head);
	deleteNodeAtTail(&list->head);

	cout << "\nLinked List After deleting 2 nodes at end: ";
	printLinkedList(list->head);

	deleteNodeAtPosition(&list->head, 0);	
	cout << "\nLinked List After deleting 2 nodes at position 0: ";
	printLinkedList(list->head);

	deleteNodeAtPosition(&list->head, 1);

	cout << "\nLinked List After deleting 2 nodes at position 1: ";
	printLinkedList(list->head);

	return 0;
}
