class Node{
        public:
          int key;
          int val;
          Node* prev;
          Node* next;

          Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
          }
    };

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*>mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        
        //dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    //addNode
    void addNode(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    //deleteNode
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        //if already exists
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;

            deleteNode(node);
            addNode(node);
        }
        else{
            //if full remove
            if(mp.size() == cap){
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */