/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void deleteNode(ListNode *Node)
{
    ListNode *Next = Node->next;
    Node->val = Next->val;
    Node->next = Next->next;
    delete Next;
}
