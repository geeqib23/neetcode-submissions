class DoublyLL{
    public:
    DoublyLL* next = nullptr;
    DoublyLL* prev = nullptr;
    int val;
    DoublyLL(int v){
        val = v;
    }
};
class LRUCache {
public:
    int cap;
    int count;
    vector<pair<DoublyLL*,int>> map;
    DoublyLL* head;
    DoublyLL* tail;
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        map.resize(1001,{NULL,-1});
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        auto &[node,val] = map[key];
        if(!node) return -1;
        if(tail == node) return val;
        if(node->prev)
            node->prev->next = node->next;
        else
            head = node->next;
        if(node->next)
            node->next->prev = node->prev;
        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        tail = node;
        return val;
    }
    
    void put(int key, int value) {
        if(map[key].first != NULL){ 
            DoublyLL* node = map[key].first;
            if(node == head) head = node->next;
            if(node->prev)
                node->prev->next = node->next;
            if(node->next)
                node->next->prev = node->prev;
            if(node == tail) tail = node->prev;
            count--;
        }
        if(!head || !tail){
            head = new DoublyLL(key);
            tail = head;
            map[key] = {head,value};
            count++;
        } else {
            DoublyLL* newNode = new DoublyLL(key);
            map[key] = {newNode,value};
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            count++;
        }
        if(count > cap){
            int oldKey = head->val;
            map[oldKey] = {NULL,-1};
            DoublyLL* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            // else tail = NULL;
            // delete temp;
            count--;
        }
    }
};