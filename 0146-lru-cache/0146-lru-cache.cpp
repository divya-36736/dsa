class LRUCache {
    class Node{
        public:
        //variables 
        int key, val;
        Node* prev;
        Node* next;

        //constructer
        Node(int k, int v){
            key = k;
            val = v;
            next = prev = NULL;
        }
    };
    Node* head = new Node(-1, -1); //dll dummy head ans tail
    Node* tail = new Node(-1, -1);

    
public:
    unordered_map<int, Node*>m;
    int limit;
    //add fun
    void addNode(Node* newNode){
        Node* oldNext = head->next; //connection save
        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }
    void delNode(Node* oldNode){
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;

        oldprev->next = oldnext;
        oldnext ->prev = oldprev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1; //not find then return -1
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        //if already exist then 1st we dlt them
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];//del node call
            delNode(oldNode);//delnode
            m.erase(key);//ab map sebhi delt kr denge
        }
        //if we reach the capacity and now we want tot insert new nod
        //then 1st we dlt tthe last recent node
        if(m.size() == limit){
            m.erase(tail->prev->key); //tail ke prev ko
            delNode(tail->prev);
        }
        //now we insert the new key and val
        Node* newNode = new Node(key, value); //new node banaege
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */