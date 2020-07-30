/*https://leetcode.com/problems/linked-list-cycle/submissions/

Solution:*/
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL) return false;
        ListNode *fast=head;
        ListNode *slow=head;
        while(slow->next!=NULL)
        {
            slow=slow->next;
            if(fast->next==NULL || fast->next->next==NULL)
                return false;
            fast=fast->next->next;

            if(slow==fast)
                return true;
        }

            return false;
    }
};