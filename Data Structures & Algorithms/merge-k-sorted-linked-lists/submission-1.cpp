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
private:
    void merge(vector<ListNode*>& V,int s, int m, int e){
        int i = s;
        int j = m + 1;

        vector<ListNode*> temp;

        while(i <= m && j <= e){
            if(V[i]->val <= V[j]->val){
                temp.push_back(V[i]);
                i++;
            }
            else {
                temp.push_back(V[j]);
                j++;
            }
        }

        while(i <= m){
            temp.push_back(V[i]);
            i++;
        }

        while(j <= e){
            temp.push_back(V[j]);
            j++;
        }

        for(int i = s; i <= e; i++){
            V[i] = temp[i - s];
        }
    }

    void helper(vector<ListNode*>& V,int s, int e){
        if(e - s + 1 <= 1)return;

        int m = s + (e - s )/ 2;

        helper(V, s, m);
        helper(V, m + 1, e);

        merge(V, s, m, e);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> V;

        for(ListNode* l : lists){
            ListNode* head = l;

            while(head){
                V.push_back(head);
                head = head->next;
            }
        }

        helper(V, 0, V.size() - 1);

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;    
        for(ListNode* n : V){
            curr->next = n;
            curr = curr->next;
        }

        return dummy->next;
    }
};
