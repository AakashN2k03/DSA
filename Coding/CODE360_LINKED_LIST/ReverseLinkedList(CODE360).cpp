// CODE360:  Reverse Linked List (SLL)

Node* reverseLinkedList(Node *head)
{
      Node* temp=head;
      Node* prev=nullptr;
      while(temp)
      {
          Node*front=temp->next;
          temp->next=prev; 
          prev=temp;
          temp=front; //here we cannot use temp=temp->next,since temp->next assigns to prev;
      }
      return prev;
}

// we can perform this code using stack too

//Time Complexity: O(n)
// Space Complexity: O(1)
