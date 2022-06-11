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

//If there is cycle in linked list return the node where cycle begin
/*
Input linked list:

         3--->2--->0--->-4
              ^          |
              |          |
               ----------

Output = 2
*/

//TC: O(N)
//SC: O(1)

SingleLinkedListNode* detectCycle(SingleLinkedListNode* head)
{
    SingleLinkedListNode* fast = head;
    SingleLinkedListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            slow = head;
            while(slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
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
    SingleLinkedListNode* node0 = new SingleLinkedListNode(3);
    SingleLinkedListNode* node1 = new SingleLinkedListNode(2);
    SingleLinkedListNode* node2 = new SingleLinkedListNode(0);
    SingleLinkedListNode* node3 = new SingleLinkedListNode(-4);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    SingleLinkedListNode* node = detectCycle(node0);

    if(node != nullptr)
        cout << "Node where cycle begins =  "<<node->data<<endl;
    else
        cout<<"There is no cycle in linked list"<<endl;

    return 0;
}
