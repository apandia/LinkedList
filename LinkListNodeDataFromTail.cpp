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

int getNodeValue(SingleLinkedListNode* head, int positionFromTail)
{
	SingleLinkedListNode* temp1 = head;
	SingleLinkedListNode* temp2 = head;

	//First move temp1 upto "positionFromTail" position
	for (int i = 0; i < positionFromTail; i++)
	{
		temp1 = temp1->next;
	}

	//Then increment both temp1 and temp2 till temp1 reaches end
	while((temp1 != nullptr) && (temp1->next != nullptr))
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return temp2->data;
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

	cout << "\nLinked List: ";
	printLinkedList(list->head);

	int positionFromTail = 2;
	cout << "\nValue at position 2 from tails: "<< 	getNodeValue(list->head, positionFromTail);

	return 0;
}
