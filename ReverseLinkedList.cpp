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

void reverseLinkedList(SingleLinkedListNode** head)
{
	if ((*head) == nullptr)
		return;

	SingleLinkedListNode* current = *head;
	SingleLinkedListNode* prev = nullptr;
	SingleLinkedListNode* next = nullptr;

	while (current)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	*head = prev;
}

SingleLinkedListNode* reverseList(SingleLinkedListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	SingleLinkedListNode* node = reverseList(head->next);
	head->next->next = head;

	head->next = nullptr;

	return node;
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

	cout << "\nLinked List after reverse: ";
	reverseLinkedList(&list->head);
	printLinkedList(list->head);


	cout << "\nLinked List after reverse (recursive): ";
	list->head = reverseList(list->head);
	printLinkedList(list->head);

	return 0;
}
