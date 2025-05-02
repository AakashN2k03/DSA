// CODE360:  Cycle Detection in a Singly Linked List (SLL)

           //     TORTOISE AND HARE  //

bool detectCycle(Node *head)
{
	Node* slow=head;
    Node* fast=head;
   
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
         if(fast==slow) return true;
    } 
    return false;
}

// Time Complexity:O(n)
// Space Complexity:O(1)

// EASY WAY USING SET or HASHMAP
 // (LEETCODE)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mpp;
        ListNode*temp=head;
        while(temp)
        {
            if(mpp.find(temp)!=mpp.end())
            {
                return true;
            }
            mpp[temp]++;
            temp=temp->next;
        }
        return false;
    }
};
