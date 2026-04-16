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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int> sums;
        while(fast && fast->next){
            sums.push_back(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        int i = 0;
        while(slow){
            sums[sums.size() - 1 - i] += slow->val;
            slow = slow->next;
            i++; 
        }
        int res = INT_MIN;

        for(int sum : sums)res = max(res,sum);

        return res;

    }
};