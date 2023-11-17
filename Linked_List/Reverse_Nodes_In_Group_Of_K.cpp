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
int Count_Node(ListNode *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
ListNode *solve_Recursive(ListNode *head, int k, int count)
{
    if (count < k)
        return head;
    int reverse = k;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr && reverse)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        reverse--;
    }
    head->next = solve_Recursive(next, k, count - k);
    return prev;
}
ListNode *solve_Iterative(ListNode *head, int k, int count)
{
    bool ishead = true;
    ListNode *NewHead = NULL;
    ListNode *prevlast = NULL;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head && count >= k)
    {
        prev = NULL;
        next = NULL;
        ListNode *curr = head;
        int reverse = k;
        while (head && reverse)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            reverse--;
        }
        if (ishead)
        {
            NewHead = prev;
            ishead = false;
        }
        else
        {
            prevlast->next = prev;
        }
        count -= k;
        prevlast = head;
        head = curr;
    }
    if (prevlast != NULL)
        prevlast->next = next;
    return NewHead;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int count = Count_Node(head);
    return solve_Iterative(head, k, count);
    return solve_Recursive(head, k, count);
}
