/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node *removeLoop(Node *head)
{
    if(head==NULL)
        return head;
    Node* Fast=head;
    Node* Slow=head;
    Node* prev=NULL;
    while(Fast!=NULL && Fast->next!=NULL)
    {
        Slow=Slow->next;
        prev=Fast->next;
        Fast=Fast->next->next;
        if(Fast==Slow)
            break;
    }
    if(Slow!=Fast)
    {
        return head;
    }
    Slow=head;
    while(Slow!=Fast)
    {
        Slow=Slow->next;
        prev=Fast;
        Fast=Fast->next;
    }
    prev->next=NULL;
    return head;
}
