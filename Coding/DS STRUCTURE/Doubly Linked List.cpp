#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        data = val;
        next = nullptr;
        prev=nullptr;
    }
};

ListNode* build_linkedlist() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third= new ListNode(3);
    ListNode* fourth= new ListNode(4);
    ListNode* fifth = new ListNode(5);
    
    head->next=second;
    head->prev=nullptr;
    
    second->next=third;
    second->prev=head;
    
    third->next=fourth;
    third->prev=second;
    
    fourth->next=fifth;
    fourth->prev=third;
    
    fifth->next=nullptr;
    fifth->prev=fourth;
    
    return head;
    
}

void forward_traverse(ListNode* head) {
    if (!head) return;
    ListNode* temp = head;
    while (temp) {
        cout << temp->data << " ";  
        temp = temp->next;
    }
    cout << endl;  
}
void backward_traverse(ListNode* tail) {
    if (!tail) return;
    ListNode* temp = tail;
    while (temp) {
        cout << temp->data << " ";  
        temp = temp->prev;
    }
    cout << endl;  
}

int main() {
    ListNode* head = build_linkedlist();
    cout << "Doubly LinkedList forward traversal:" << endl;
    forward_traverse(head);
    
    ListNode* tail=head;
    while(tail->next)
    {
        tail=tail->next;
    }
     cout << "Doubly LinkedList backward traversal:" << endl;
    backward_traverse(tail);
    return 0;
}
