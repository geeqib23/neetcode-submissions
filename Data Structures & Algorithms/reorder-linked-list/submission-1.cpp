/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        unordered_map<ListNode*,ListNode*> prev;
        ListNode* curr = head;
        while(curr->next){
            prev[curr->next] = curr;
            curr = curr->next;
        }
        ListNode *left = head; 
        ListNode *right = curr; 
        while(true){
            ListNode* temp1 = left->next; 
            if(temp1 == right){
                right->next = NULL;
                break;
            }   
            ListNode* temp2 = prev[right];
            left->next = right;
            right->next = temp1;
            left = temp1;
            right = temp2;    
            if(temp1 == temp2){
                temp1->next = NULL;
                break;
            } 
        }
        
    }
};
