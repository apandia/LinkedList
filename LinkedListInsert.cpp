#include <iostream>

using namespace std;

//Linked list insert: tail, head and specifc position

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

//Insert new node at start
void insertNodeAtStart(SingleLinkedListNode** head, int data)
{
	SingleLinkedListNode* newNode = new SingleLinkedListNode(data);

	//Set the current head as next node of new node
	newNode->next = (*head);

	//Set the head to new node
	(*head) = newNode;
}

void insertNodeAtPosition(SingleLinkedListNode** head, int data, int position)
{
	if (*head == nullptr)
		return;

	SingleLinkedListNode* newNode = new SingleLinkedListNode(data);

	SingleLinkedListNode* temp = *head;
	int currentPos = 0;

	//Iterate till previous value for given position value
	while (temp) {
		if (currentPos == (position - 1))
			break;

		temp = temp->next;
		currentPos++;
	}

	//make the newNode point to bext node of temp node
	newNode->next = temp->next;

	//Now point the temp node to new node
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

//Driver function
int main()
{
	SingleLinkList* list = new SingleLinkList;

	insertNodeAtTail(&list->head, 10);
	insertNodeAtTail(&list->head, 20);
	insertNodeAtTail(&list->head, 30);
	insertNodeAtTail(&list->head, 40);

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	insertNodeAtStart(&list->head, 5);
	insertNodeAtStart(&list->head, 0);	

	cout << "\nLinked List After Inserting at start: ";
	printLinkedList(list->head);

	insertNodeAtPosition(&list->head, 15, 3);
	insertNodeAtPosition(&list->head, 25, 5);

	cout << "\nLinked List After Inserting at positin 3: ";
	printLinkedList(list->head);

	return 0;
}