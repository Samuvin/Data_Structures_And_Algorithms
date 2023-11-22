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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    //     if(list1==NULL)
    //         return list2;
    //     if(list2==NULL)
    //         return list1;
    //     ListNode* head=NULL;
    //     ListNode* tail=NULL;
    //     if(list1->val<=list2->val)
    //     {
    //         head=tail=list1;
    //         list1=list1->next;
    //     }    
    //     else
    //     {
    //         head=tail=list2;
    //         list2=list2->next;
    //     }
    //     while(list1!=NULL && list2!=NULL)
    //     {
    //         if(list1->val<=list2->val)
    //         {
    //             tail->next=list1;
    //             tail=list1;
    //             list1=list1->next;
    //         }
    //         else
    //         {
    //             tail->next=list2;
    //             tail=list2;
    //             list2=list2->next;
    //         }
    //     }
    //     if(list1==NULL)
    //         tail->next=list2;
    //     if(list2==NULL)
    //         tail->next=list1;
    //     return head;
    // }

    // if(list1==NULL)
    //     return list2;
    // if(list2==NULL)
    //     return list1;
    // ListNode* l1=list1;
    // ListNode* l2=list2;
    // if(l2->val<l1->val)
    //     swap(l1,l2);
    // ListNode* head=l1;
    // ListNode* prev=NULL;
    // while(l1!=NULL && l2!=NULL)
    // {
    //     while(l1!=NULL && l1->val<=l2->val)
    //     {
    //         prev=l1;
    //         l1=l1->next;
    //     }
    //     prev->next=l2;
    //     swap(l1,l2);
    // }
    // return head;

    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->val<=list2->val)
    {
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }

}
