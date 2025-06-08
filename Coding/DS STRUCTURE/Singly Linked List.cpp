#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

ListNode* build_linkedlist() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

void traverse(ListNode* head) {
    if (!head) return;
    ListNode* temp = head;
    while (temp) {
        cout << temp->data << " ";  
        temp = temp->next;
    }
    cout << endl;  
}

int main() {
    ListNode* head = build_linkedlist();
    cout << "LinkedList traversal:" << endl;
    traverse(head);
    return 0;
}
