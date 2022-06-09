#include <iostream>

using namespace std;

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

SingleLinkedListNode* deleteNthNodeFromEnd(SingleLinkedListNode* head, int n)
{
    SingleLinkedListNode* fast = head;
    SingleLinkedListNode* slow = head;

    for(int i = 0; i < n; i++)
    {
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next;
    }

    if(fast == nullptr)
        return nullptr;

    while(fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}

//Driver function
int main()
{
    SingleLinkedListNode* head = new SingleLinkedListNode(1);

    insertNodeAtTail(head, 2);
    insertNodeAtTail(head, 3);
    insertNodeAtTail(head, 4);
    insertNodeAtTail(head, 5);

    cout << "\nLinked List: ";
    printLinkedList(head);

    SingleLinkedListNode* newHead = deleteNthNodeFromEnd(head, 2);

    cout << "\nNew linked list after deleting 2nd node from end: ";
    printLinkedList(newHead);

    return 0;
}
