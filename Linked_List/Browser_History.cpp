class Node {
public:
    string data;
    Node* prev;
    Node* next;
    Node(string data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory {
public:
    Node* Current;
    BrowserHistory(string homepage) 
    { 
        Current = new Node(homepage); 
    }

    void visit(string url) {
        Node* newnode = new Node(url);
        Current->next = newnode;
        newnode->prev = Current;
        Current = Current->next;
    }

    string back(int steps) {
        while (steps && Current->prev) {
            steps--;
            Current = Current->prev;
        }
        return Current->data;
    }

    string forward(int steps) {
        while (steps && Current->next) {
            steps--;
            Current = Current->next;
        }
        return Current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
