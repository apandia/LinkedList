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

//Add 2 numbers from linked list and return a new linked list

/*
Input Linked List1: 2->4->3
Input Linked List2: 5->6->7->9

Output Linked List: 7->0->1->0->1
*/

//TC: O(max(m,n))   [m = number of nodes in list1, n = number of nodes in list2]
//SC: O(N)          [total number of digits in output sum]

SingleLinkedListNode* addTwoNumbers(SingleLinkedListNode* l1, SingleLinkedListNode* l2)
{
    SingleLinkedListNode* dummy = new SingleLinkedListNode();

    SingleLinkedListNode* tmp = dummy;

    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry !=0 )
    {
        int sum = 0;

        if(l1 != nullptr)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != nullptr)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum/10;

        SingleLinkedListNode* node = new SingleLinkedListNode(sum%10);

        tmp->next = node;
        tmp = tmp->next;
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
    SingleLinkedListNode* list1 = new SingleLinkedListNode(2);
    insertNodeAtTail(list1, 4);
    insertNodeAtTail(list1, 3);

    SingleLinkedListNode* list2 = new SingleLinkedListNode(5);
    insertNodeAtTail(list2, 6);
    insertNodeAtTail(list2, 7);
    insertNodeAtTail(list2, 9);

    cout << "Input Linked List1: ";
    printLinkedList(list1);
    cout<<endl;

    cout << "Input Linked List2: ";
    printLinkedList(list2);
    cout<<endl;

    SingleLinkedListNode* newHead = addTwoNumbers(list1, list2);

    cout << "Output Linked List: ";
    printLinkedList(newHead);
    cout<<endl;

    return 0;
}
