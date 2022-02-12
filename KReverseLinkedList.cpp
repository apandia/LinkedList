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

void printLinkedList(SingleLinkedListNode* head)
{
	SingleLinkedListNode* current = head;

	while (current) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

SingleLinkedListNode* kRreverseLinkedList(SingleLinkedListNode* head, int k)
{
	if (head == nullptr)
		return head;

	//reverse the linked list for first k lement
	SingleLinkedListNode* curr = head;
	SingleLinkedListNode* prev = nullptr;
	SingleLinkedListNode* next = nullptr;

	int counter = 0;

	while ((curr != nullptr) && (counter < k))
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;

		counter++;
	}

	if (next != nullptr) {
		head->next = kRreverseLinkedList(next, k);
	}

	return prev;
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

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	cout << "\nLinked List after k reverse: ";
	SingleLinkedListNode* head = kRreverseLinkedList(list->head, 3);
	printLinkedList(head);

	return 0;
}