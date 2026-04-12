class Solution {

private:
    void dfs(
        vector<int>& candidates,
        int i,
        int sum,
        vector<int>& subset,
        int target,
        vector<vector<int>>& res
    ){

        if(sum == target){
            res.push_back(subset);
            return;
        }
        
        if(i >= candidates.size() || sum > target) return;

        subset.push_back(candidates[i]);
        dfs(candidates, i+1, sum + candidates[i], subset, target,res);
        subset.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        dfs(candidates, i+1, sum, subset, target,res);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, 0, subset, target, res);

        return res;
    }
};
