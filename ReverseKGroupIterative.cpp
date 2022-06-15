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

//Reverse a linked list in K group

/*
Input Linked List: 1->2->3->4->5

K = 2
Output: 2->1->4->3->5

K = 3
Output: 3->2->1->4->5
*/

//TC: O(N)
//SC: O(1)
int getLinkedListSize(SingleLinkedListNode* head)
{
    SingleLinkedListNode* tmp = head;
    int count = 0;

    while(tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

SingleLinkedListNode* reverseKGroup(SingleLinkedListNode* head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 1)
        return head;

    int linkedListSize = getLinkedListSize(head);

    SingleLinkedListNode* dummy = new SingleLinkedListNode(0);
    dummy->next = head;

    SingleLinkedListNode* curr;
    SingleLinkedListNode* next;
    SingleLinkedListNode* prev = dummy;

    while(linkedListSize >= k)
    {
        curr = prev->next;
        next = curr->next;

        for(int i = 0; i < k-1; i++) //For value of K we need to break k-1 links in group of k
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        linkedListSize -= k;
        prev = curr;
    }

    return dummy->next;
}

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

    /*SingleLinkedListNode* newHead = reverseKGroup(head, 2);

    cout << "New linked list after reversing group of 2 nodes: ";
    printLinkedList(newHead);
    cout<<endl;*/

    SingleLinkedListNode* newHead = reverseKGroup(head, 3);

    cout << "New linked list after reversing group of 3 nodes: ";
    printLinkedList(newHead);

    return 0;
}
