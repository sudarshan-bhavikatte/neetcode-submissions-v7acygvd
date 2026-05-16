class Solution {
    vector<vector<int>> res;
    int n;
    int k;

    void helper(int cur, vector<int>& subset){
        if(subset.size() == k){
            res.push_back(subset);
            return;
        }
        if(cur > n || subset.size() > k){
            return;
        }

        subset.push_back(cur);
        helper(cur + 1, subset);
        subset.pop_back();
        helper(cur + 1, subset);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        vector<int> subset;
        helper(1, subset);

        return res;
    }
};