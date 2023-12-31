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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int carry=0;
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(l1!=NULL || l2!=NULL || carry)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum=sum+l2->val;
                l2=l2->next;
            }
            sum=(sum+carry);
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }    
        return head->next;
    }
};
