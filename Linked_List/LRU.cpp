class Node {
public:
    int data;
    int key;
    Node* next;
    Node* prev;

public:
    Node(int key, int data) {
        this->data = data;
        this->key = key;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    map<int, Node*> lookup;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) {
        lookup.clear();
        head->next = tail;
        tail->prev = head;
        this->cap = capacity;
    }
    void DeleteNode(Node* del) {
        Node* prev = del->prev;
        Node* next = del->next;
        prev->next = next;
        next->prev = prev;
    }
    void AddNode(Node* node) {
        Node* next = head->next;
        node->next = next;
        next->prev = node;
        node->prev = head;
        head->next = node;
    }
    int get(int key) {
        if (lookup.find(key) == lookup.end())
            return -1;
        Node* value = lookup[key];
        DeleteNode(value);
        AddNode(value);
        return value->data;
    }

    void put(int key, int value) {
        if (lookup.find(key) != lookup.end()) {
            Node* curr = lookup[key];
            curr->data = value;
            DeleteNode(curr);
            AddNode(curr);
        } else {
            if (lookup.size() == cap) {
                Node* del = tail->prev;
                lookup.erase(del->key);
                DeleteNode(del);
                delete del;
            }
            Node* newnode = new Node(key, value);
            lookup[key] = newnode;
            AddNode(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
