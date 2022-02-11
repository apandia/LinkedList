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

SingleLinkedListNode* mergeSortedLists(SingleLinkedListNode* list1, SingleLinkedListNode* list2)
{
	if (list1 == nullptr)
		return list2;

	if (list2 == nullptr)
		return list1;

	SingleLinkedListNode* mergedList = nullptr;

	if (list1->data <= list2->data)
	{
		mergedList = list1;
		mergedList->next = mergeSortedLists(list1->next, list2);
	}
	else
	{
		mergedList = list2;
		mergedList->next = mergeSortedLists(list1, list2->next);
	}

	return mergedList;
}

//Driver function
int main()
{
	SingleLinkList* list1 = new SingleLinkList;

	insertNodeAtTail(&list1->head, 1);
	insertNodeAtTail(&list1->head, 3);
	insertNodeAtTail(&list1->head, 5);
	insertNodeAtTail(&list1->head, 7);

	cout << "\nLinked List1: ";
	printLinkedList(list1->head);

	SingleLinkList* list2 = new SingleLinkList;

	insertNodeAtTail(&list2->head, 1);
	insertNodeAtTail(&list2->head, 2);
	insertNodeAtTail(&list2->head, 4);
	insertNodeAtTail(&list2->head, 6);
	insertNodeAtTail(&list2->head, 8);
	insertNodeAtTail(&list2->head, 10);

	cout << "\nLinked List2: ";
	printLinkedList(list2->head);

	SingleLinkedListNode* mergedList = mergeSortedLists(list1->head, list2->head);

	cout << "\nSorted Linked List: ";
	printLinkedList(mergedList);

	return 0;
}
