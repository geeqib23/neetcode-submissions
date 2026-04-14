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
        int len = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }
        curr = head;
        for(int i=1;i<(len-n+1)-1;i++)
            curr = curr->next;
        if(len-n == 0) return head->next;
        ListNode* rem = curr->next;
        curr->next = rem->next;
        return head;

    }
};
