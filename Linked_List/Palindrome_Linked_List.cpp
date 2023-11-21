/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }    
        slow->next=reverse(slow->next);
        fast=slow->next;
        slow=head;
        while(fast)
        {
            if(slow->val!=fast->val)
            {
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
