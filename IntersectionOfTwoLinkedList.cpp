#include <iostream>

using namespace std;

//Find the intersection points of 2 linked lists

/*
Input Linked Lists:

List1:        4--->1--->8--->4--->5
                        ^
                        |
List2:        5--->6--->1

Intersection point of list1 and list2 = : 8
*/

//TC: O(N)
//SC: O(1)

class SingleLinkedListNode {
public:
    int data;
    SingleLinkedListNode* next;

    SingleLinkedListNode() : data(0), next(nullptr) {}
    SingleLinkedListNode(int x) : data(x), next(nullptr) {}
    SingleLinkedListNode(int x, SingleLinkedListNode *next) : data(x), next(next) {}
};

//Insert new node at tail
void insertNodeAtTail(SingleLinkedListNode* head, int data)
{
    SingleLinkedListNode* newNode = new SingleLinkedListNode(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    SingleLinkedListNode* temp = head;

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

SingleLinkedListNode* getIntersectionNode(SingleLinkedListNode* head1, SingleLinkedListNode* head2)
{
    SingleLinkedListNode* list1 = head1;
    SingleLinkedListNode* list2 = head2;

    while(list1 != list2)
    {
        list1 = (list1 != nullptr) ? list1->next : head2;
        list2 = (list2 != nullptr) ? list2->next : head1;
    }

    return list1;
}

//Driver function
int main()
{
    SingleLinkedListNode* head1 = new SingleLinkedListNode(4);

    SingleLinkedListNode* node1 = new SingleLinkedListNode(1);
    SingleLinkedListNode* node8 = new SingleLinkedListNode(8);
    SingleLinkedListNode* node4 = new SingleLinkedListNode(4);
    SingleLinkedListNode* node5 = new SingleLinkedListNode(5);

    head1->next = node1;
    node1->next = node8;
    node8->next = node4;
    node4->next = node5;


    cout << "\nLinked List1: ";
    printLinkedList(head1);

    SingleLinkedListNode* head2 = new SingleLinkedListNode(5);

    SingleLinkedListNode* node6 = new SingleLinkedListNode(6);
    SingleLinkedListNode* node11 = new SingleLinkedListNode(1);

    head2->next = node6;
    node6->next = node11;
    node11->next = node8;

    cout << "\nLinked List2: ";
    printLinkedList(head2);

    SingleLinkedListNode* node = getIntersectionNode(head1, head2);

    cout << "\nIntersection point of list1 and list2 = : "<<node->data<<endl;

    return 0;
}
