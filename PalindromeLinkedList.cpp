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

//Check if linked list is pallindrome

/*
Input Linked List1: 1->2->1
Output: True

Input Linked List2: 1->2->2->1
Output: True

Output Linked List: 1->2->3->2
Output: False
*/

//TC: O(N/2) + O(N/2) + O(N/2)
//              O(N/2): Finding middle element
//              O(N/2): Reverse right half of linked list
//              O(N/2): Comparing left and right half
//SC: O(1)      [No extra space used]

SingleLinkedListNode* reverseLinkedList(SingleLinkedListNode* head)
{
    SingleLinkedListNode* next = nullptr;
    SingleLinkedListNode* prev = nullptr;

    while(head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool checkPallindrome(SingleLinkedListNode* list)
{
    if(list == nullptr || list->next == nullptr)
        return true;

    SingleLinkedListNode* slow = list;
    SingleLinkedListNode* fast = list;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseLinkedList(slow->next);
    slow = slow->next;

    while(slow)
    {
        if(list->data != slow->data)
            return false;

        list = list->next;
        slow = slow->next;
    }

    return true;
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
    SingleLinkedListNode* list1 = new SingleLinkedListNode(1);
    insertNodeAtTail(list1, 2);
    insertNodeAtTail(list1, 1);

    SingleLinkedListNode* list2 = new SingleLinkedListNode(1);
    insertNodeAtTail(list2, 2);
    insertNodeAtTail(list2, 2);
    insertNodeAtTail(list2, 1);

    SingleLinkedListNode* list3 = new SingleLinkedListNode(1);
    insertNodeAtTail(list3, 2);
    insertNodeAtTail(list3, 3);
    insertNodeAtTail(list3, 2);

    cout << "Input Linked List1: ";
    printLinkedList(list1);
    if(checkPallindrome(list1))
        cout<<"List is Palindrome"<<endl;
    else
        cout<<"List is not pallindrome"<<endl;
    cout<<endl;

    cout << "Input Linked List2: ";
    printLinkedList(list2);
    if(checkPallindrome(list2))
        cout<<"List is Palindrome"<<endl;
    else
        cout<<"List is not pallindrome"<<endl;
    cout<<endl;

    cout << "Input Linked List3: ";
    printLinkedList(list3);
    if(checkPallindrome(list3))
        cout<<"List is Palindrome"<<endl;
    else
        cout<<"List is not pallindrome"<<endl;

    cout<<endl;

    return 0;
}
