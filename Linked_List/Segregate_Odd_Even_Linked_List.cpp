/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};*/
Node *divide(int N, Node *Head)
{
    Node *Even_Head = NULL;
    Node *Even_Tail = NULL;
    Node *Odd_Head = NULL;
    Node *Odd_Tail = NULL;
    Node *T_Head = Head;
    while (Head)
    {
        if ((Head->data & 1) == 0)
        {
            if (Even_Head == NULL)
            {
                Even_Head = Head;
                Even_Tail = Head;
            }
            else
            {
                Even_Tail->next = Head;
                Even_Tail = Head;
            }
        }
        else
        {
            if (Odd_Head == NULL)
            {
                Odd_Head = Head;
                Odd_Tail = Head;
            }
            else
            {
                Odd_Tail->next = Head;
                Odd_Tail = Head;
            }
        }
        Head = Head->next;
    }
    if (Even_Head == NULL || Odd_Head == NULL)
        return T_Head;
    Even_Tail->next = Odd_Head;
    Odd_Tail->next = NULL;
    return Even_Head;
}
