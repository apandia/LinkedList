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

bool detecCycle(SingleLinkedListNode* head)
{
	if (head == nullptr)
		return false;

	SingleLinkedListNode* slow = head;
	SingleLinkedListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return true;
	}

	return false;
}

int getIntersectionNode(int difference, SingleLinkedListNode* head1, SingleLinkedListNode* head2)
{
	SingleLinkedListNode* temp1 = head1;
	SingleLinkedListNode* temp2 = head2;

	//Move the first node by difference value
	for (int i = 0; i < difference; i++) {
		if (temp1 == nullptr) {
			return -1;
		}
		temp1 = temp1->next;
	}

	//Both the list now have same number of elements to tail
	//Iterate both and check if they have common node
	while (temp1 != nullptr && temp2 != nullptr)
	{
		if (temp1 == temp2)
		{
			return temp1->data;
		}

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return -1;
}

int findMergeNode(SingleLinkedListNode* head1, SingleLinkedListNode* head2) {
	SingleLinkedListNode* temp1 = head1;
	SingleLinkedListNode* temp2 = head2;

	//count the size of list1
	int listSize1 = 0;
	while (temp1) {
		temp1 = temp1->next;
		listSize1++;
	}

	//count the size of list2
	int listSize2 = 0;
	while (temp2) {
		temp2 = temp2->next;
		listSize2++;
	}

	int difference = 0;
	if (listSize1 > listSize2) {
		difference = listSize1 - listSize2;
		return getIntersectionNode(difference, head1, head2);
	}
	else {
		difference = listSize2 - listSize1;
		return getIntersectionNode(difference, head2, head1);
	}

}

//Driver function
int main()
{
	SingleLinkList* list1 = new SingleLinkList;

	insertNodeAtTail(&list1->head, 10);
	insertNodeAtTail(&list1->head, 20);
	insertNodeAtTail(&list1->head, 30);
	insertNodeAtTail(&list1->head, 40);

	cout << "\nLinked List1: ";
	printLinkedList(list1->head);

	SingleLinkList* list2 = new SingleLinkList;

	insertNodeAtTail(&list2->head, 1);
	insertNodeAtTail(&list2->head, 2);
	insertNodeAtTail(&list2->head, 3);

	//set the last node of list 2 to point to 2nd node of list1
	//list2: 1->2->3->20->30->40->NULL

	//Use temporary pointer to go till last element of list2
	SingleLinkedListNode* temp1 = list2->head;
	while (temp1->next)
	{
		temp1 = temp1->next;
	}

	//Go till 2nd element of list1 i.e. node with value 10
	SingleLinkedListNode* temp2 = list1->head;
	int counter = 0;
	while(temp2){
		if (counter == 1) {
			temp1->next = temp2;
			break;
		}
		temp2 = temp2->next;
		counter++;
	}

	cout << "\nLinked List2: ";
	printLinkedList(list2->head);

	cout << "Mergepoint = " << findMergeNode(list1->head, list2->head) << endl;

	

	return 0;
}