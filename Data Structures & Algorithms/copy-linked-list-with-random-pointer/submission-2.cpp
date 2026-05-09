/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* headCopy = head;
        Node* headNew = new Node(head->val);
        Node* node = headNew;
        unordered_map<Node*,Node*> hs;
        while(head){
            hs[head] = node;
            if(head->next){
                if(hs.count(head->next)){
                    node->next = hs[head->next];
                }
                else{
                    node->next = new Node(head->next->val);
                    hs[head->next] = node->next;
                }
            }
            if(head->random){
                if(hs.count(head->random)){
                    node->random = hs[head->random];
                }
                else{
                    node->random = new Node(head->random->val);
                    hs[head->random] = node->random;
                }
            }
            node = node->next;
            head = head->next;
        }
        node = headNew;
        head = headCopy;
        while(head){
            if(head->random)
                node->random = hs[head->random];
            head = head->next;
            node = node->next;
        }
        return headNew;
        
    }
};
