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

struct listNodeComparator {

    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>,listNodeComparator> pq;

       for(ListNode* head:lists){
        pq.push(head);
       }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(!pq.empty()){
            ListNode* small = pq.top();
            pq.pop();
            curr->next = small;
            curr = curr->next;

            if(small->next){
                pq.push(small->next);
            }
        }
        return dummy.next;
    }
};
