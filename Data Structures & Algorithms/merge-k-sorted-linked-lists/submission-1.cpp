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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* head = dummyHead;
        for(int i = 0;i<lists.size();i++){
            if(lists[i] == NULL) continue;
            pq.push({lists[i]->val,i});
        }
        int c = 0;
        while(!pq.empty()){
            // c++;
            // if(c == 10) break;
            int minIndex = pq.top().second;
            int minValue = pq.top().first;
            pq.pop();
            // head->next = new ListNode(minValue); DONT MAKE NEW NODE THIS WE NEED TO MERGE
            head->next = lists[minIndex];
            head = head->next;
            // ListNode* minNode = lists[minIndex];   //Dont use var, it does not move the actual node forward
            if(lists[minIndex]->next != NULL){
                lists[minIndex] = lists[minIndex]->next;
                pq.push({lists[minIndex]->val,minIndex});
            }
        }
        return dummyHead->next;

    }
};
