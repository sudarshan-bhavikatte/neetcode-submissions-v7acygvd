class Solution {
    vector<vector<int>> res;
    int target;

    void helper(vector<int>& candidates,
        vector<int>& subset,
        int i,
        int sum
    ) {
        if(sum == target){
            res.push_back(subset);
            return;
        }

        if(sum > target || i >= candidates.size()){
            return;
        }

        subset.push_back(candidates[i]);
        helper(candidates, subset, i + 1, sum + candidates[i]);
        subset.pop_back();

        while(i + 1 < candidates.size() &&
              candidates[i] == candidates[i + 1]) {
            i++;
        }
        
        helper(candidates, subset, i + 1, sum);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        helper(candidates, subset, 0, 0);

        return res;
    }
};
