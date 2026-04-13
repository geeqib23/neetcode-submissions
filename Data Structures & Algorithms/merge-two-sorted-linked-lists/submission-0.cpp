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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node1=list1,*node2=list2;
        ListNode dummy = ListNode(101);
        ListNode *curr = &dummy;
        while(node1 != NULL || node2 != NULL){
            if(node1 == NULL)
            {
                curr->next = node2;
                node2 = node2->next;
                curr = curr->next;
            }
            else if(node2 == NULL){
                curr->next = node1;
                node1 = node1->next;
                curr = curr->next;
            }
            else if(node1->val<=node2->val){
                curr->next = node1;
                node1 = node1->next;
                curr = curr->next;
            }
            else{
                curr->next = node2;
                node2 = node2->next;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
