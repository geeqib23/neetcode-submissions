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
            if(head->next)
                node->next = new Node(head->next->val);
            hs[head] = node;
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
