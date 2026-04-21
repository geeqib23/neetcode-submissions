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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev = dummy;
        while(true){
            // cout << groupPrev->val << " " << groupPrev->next->val << " " << endl;
            ListNode* kth = getKth(groupPrev,k);
            if(!kth)
                break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;

        }
        return dummy->next;
    }
    
    ListNode* getKth(ListNode* node, int k){
        while(node && k>0){
            node = node->next;
            --k;
        }
        return node;
    }
};
