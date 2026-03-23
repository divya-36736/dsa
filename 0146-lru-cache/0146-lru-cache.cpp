class LRUCache {
public:
    //dubly linked list node class
    class Node{
        public:
             int key;
             int val;
             Node* next;
             Node* prev;

             //constructor
             Node(int _key, int _val){
                key  = _key;
                val = _val;
             }
    };

    //head ans tail dummy nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*>m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    //fuction to add a node right after head
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    //function to remove a given node from list
    void deleteNode(Node* delNode){
        Node* delprev = delNode->prev;
        Node* delNext = delNode->next;
        delprev->next = delNext;
        delNext->prev = delprev;
    }
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int res = resNode->val;
            //remove old mapping
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //if already exists
        if(m.find(key) != m.end()){
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        //if capacity reached
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //insert new node at front
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */