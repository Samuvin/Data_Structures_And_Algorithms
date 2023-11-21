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
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) 
            return head;
        ListNode* curr=head->next->next;
        ListNode* prev=head;
        head=head->next;
        head->next=prev;
        while(curr && curr->next!=NULL)
        {
            ListNode* next=curr->next->next;
            prev->next=curr->next;
            curr->next->next=curr;
            prev=curr;
            curr=next;
        }
        prev->next=curr;
        return head;


        // ListNode* curr=head;
        // while(curr && curr->next!=NULL)
        // {
        //     swap(curr->val,curr->next->val);
        //     curr=curr->next->next;
        // }
        // return head;
    }
};
