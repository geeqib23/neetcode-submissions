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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* dummy = new ListNode(-1,head);
        ListNode* left = dummy;
        ListNode* right = dummy;
        for(int i =0;i<n;i++)
            right = right->next;
        while(right->next != NULL){
            left = left->next;
            right = right->next;
        }
        if(left == dummy) return left->next->next;
        left->next = left->next->next;
        return head;

    }
};
