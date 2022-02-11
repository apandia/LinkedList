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

bool compareLinkedLists(SingleLinkedListNode* list1, SingleLinkedListNode* list2)
{
	SingleLinkedListNode* temp1 = list1;
	SingleLinkedListNode* temp2 = list2;

	while ((temp1 != nullptr) || (temp1 != nullptr))
	{
		if ((temp1 == nullptr) || (temp2 == nullptr))
		{
			return false;
		}

		if (temp1->data != temp2->data)
			return false;

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return true;
}

//Driver function
int main()
{
	SingleLinkList* list1 = new SingleLinkList;

	insertNodeAtTail(&list1->head, 10);
	insertNodeAtTail(&list1->head, 20);
	insertNodeAtTail(&list1->head, 30);
	insertNodeAtTail(&list1->head, 40);
	insertNodeAtTail(&list1->head, 50);

	cout << "\nLinked List1: ";
	printLinkedList(list1->head);

	SingleLinkList* list2 = new SingleLinkList;

	insertNodeAtTail(&list2->head, 10);
	insertNodeAtTail(&list2->head, 20);
	insertNodeAtTail(&list2->head, 30);
	insertNodeAtTail(&list2->head, 40);
	insertNodeAtTail(&list2->head, 50);

	cout << "\nLinked List2: ";
	printLinkedList(list1->head);

	if (compareLinkedLists(list1->head, list2->head))
		cout << "\nLinked lists are same";
	else
		cout << "\nLinked Lists are not same";

	return 0;
}
