class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
    void insertAtStart(Node* node){
        Node* tmp = head->next;
        head->next = node;
        node->prev = head;
        node->next = tmp;
        tmp->prev = node;
    }
    void removeNode(Node* node){
       node->prev->next = node->next;
       node->next->prev = node->prev;
    }
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int value = mp[key]->value;
        removeNode(mp[key]);
        insertAtStart(mp[key]);
        return value;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            Node* node = new Node(key, value);
            mp[key] = node;
            insertAtStart(node);
        }
        else{
            mp[key]->value = value;
            removeNode(mp[key]);
            insertAtStart(mp[key]);
        }
        if(mp.size() > cap){
            Node* lru = tail->prev;
            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
    }
};
