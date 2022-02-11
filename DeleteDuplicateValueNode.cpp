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

SingleLinkedListNode* deleteDuplicateValueNode(SingleLinkedListNode* head)
{
	SingleLinkedListNode* current = head->next;
	SingleLinkedListNode* prev = head;

	while (current != nullptr)
	{
		if (current->data == prev->data)
		{
			SingleLinkedListNode* temp = current;
			current = current->next;
			prev->next = current;

			delete temp;
			temp = nullptr;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}

	return head;
}

//Driver function
int main()
{
	SingleLinkList* list = new SingleLinkList;

	insertNodeAtTail(&list->head, 10);
	insertNodeAtTail(&list->head, 20);
	insertNodeAtTail(&list->head, 20);
	insertNodeAtTail(&list->head, 30);
	insertNodeAtTail(&list->head, 30);
	insertNodeAtTail(&list->head, 30);
	insertNodeAtTail(&list->head, 40);
	insertNodeAtTail(&list->head, 50);
	insertNodeAtTail(&list->head, 50);

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	int positionFromTail = 2;
	SingleLinkedListNode* uniqueList = deleteDuplicateValueNode(list->head);
	
	cout << "\nLinked List after deletion of duplicate values: ";
	printLinkedList(uniqueList);

	return 0;
}
