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

//Rotate Linked List

/*
Input Linked List1: 1->2->3->4->5
K = 2

Rotate 1: 5->1->2->3->4
Rotate 2: 4->5->1->2->3
*/

//TC: O(N) + O(N-(N%K))
//              [ O(N): Finding length of linked list]
//              [ O(N-(N%K)): For traversing till the node to break the link]
//SC: O(1)      [ No extra space used]

SingleLinkedListNode* rotateRightLinkedList(SingleLinkedListNode* head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;

    //1. Get the lenth of linked list.curr will point to node 5
    SingleLinkedListNode* curr = head;
    int length = 1;
    while(curr->next){
        curr = curr->next;
        length++;
    }

    //2.Make curr point to head(it will make the linked list circular)
    curr->next = head;

    //3/Calculate the final k value by which we have to rotate.
    //Note: If the list size is N, then if we rotate the list by N the list will be same as earlier.
    //So final rotate will be (total lentgh - k % length). Say we want to rotate above list by k = 7
    //Then final rotate value = (7%5) = 2 . So rotating by 7 is same as rotating by 2
    //To rotate the list by 2 we need to move the element by 3 position and cut the link i.e move the head by
    //length-k position
    //So the rule is: len - (len % k)
    k = k % length;
    k = length - k;
    while(k--) //curr will point to node 3 after while loop
    {
        curr = curr->next;
    }

    //4.Make the node as head and break the link
    head = curr->next; //node 4 will be head now
    curr->next = nullptr; //make next of node 3 to nullptr

    return head;
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
    SingleLinkedListNode* list = new SingleLinkedListNode(1);
    insertNodeAtTail(list, 2);
    insertNodeAtTail(list, 3);
    insertNodeAtTail(list, 4);
    insertNodeAtTail(list, 5);

    cout << "Input Linked List: ";
    printLinkedList(list);

    int k = 2;
    SingleLinkedListNode* newHead = rotateRightLinkedList(list, k);

    cout<<"List after rotating by "<<k<<" = ";
    printLinkedList(newHead);

    return 0;
}
