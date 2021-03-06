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

SingleLinkedListNode* getMiddleNode(SingleLinkedListNode* head)
{
    if(head == nullptr)
        return nullptr;

    SingleLinkedListNode* fast = head;
    SingleLinkedListNode* slow = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

SingleLinkedListNode* deleteMiddle(SingleLinkedListNode* head)
{
    SingleLinkedListNode* middleNode = getMiddleNode(head);

    SingleLinkedListNode* tmp = middleNode->next;

    if(tmp)
    {
        middleNode->data = tmp->data;
        middleNode->next = tmp->next;

        delete tmp;
        tmp = nullptr;
    }
    else if(head->next == middleNode)
    {
        head->next = nullptr;

        delete middleNode;
        middleNode = nullptr;
    } else{
        return nullptr;
    }

    return head;
}

//Below function has nearly same memory usage but faster runtime
SingleLinkedListNode* deleteMiddleNode(SingleLinkedListNode* head) {
    SingleLinkedListNode tmp(0, head);
    SingleLinkedListNode* slow = &tmp;
    SingleLinkedListNode* fast = &tmp;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // delete the middle node
    slow->next = slow->next->next;
    return tmp.next;
  }

//Driver function
int main()
{
    SingleLinkedListNode* head = new SingleLinkedListNode(1);

    insertNodeAtTail(head, 3);
    insertNodeAtTail(head, 4);
    insertNodeAtTail(head, 7);
    insertNodeAtTail(head, 1);
    insertNodeAtTail(head, 2);
    insertNodeAtTail(head, 6);

    cout << "\nLinked List: ";
    printLinkedList(head);

    //SingleLinkedListNode* newHead = deleteMiddle(head);
    SingleLinkedListNode* newHead = deleteMiddleNode(head);
    cout << "\nNew Linked List After Deleting Middle: ";
    printLinkedList(newHead);

    return 0;
}
