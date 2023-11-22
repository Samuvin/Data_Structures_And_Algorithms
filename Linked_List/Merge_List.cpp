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
    ListNode* merge(ListNode* list1,ListNode* list2)
    {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        if(list1->val<=list2->val)
        {
            head=list1;
            tail=list1;
            list1=list1->next;
        }
        else
        {
            head=list2;
            tail=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }
            else
            {
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL)
            tail->next=list2;
        if(list2==NULL)
            tail->next=list1;
        return head;
    }
    ListNode* sortList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast && fast->next)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }  
        prev->next=NULL;
        ListNode* first=head;
        ListNode* second=slow;
        first=sortList(first);
        second=sortList(second);
        
        return merge(first,second);
    }
};
