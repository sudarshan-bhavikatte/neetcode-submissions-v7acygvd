class Solution {
    vector<int> nums;
    vector<int> subSetSum;
    int sum;

    bool dfs(int idx){
        if(idx == nums.size()) return true;

        for(int i = 0; i < subSetSum.size(); i++){
            if(subSetSum[i] + nums[idx] <= sum){
                subSetSum[i] += nums[idx];
                if(dfs(idx + 1)) return true;
                subSetSum[i] -= nums[idx];
            }

            if(subSetSum[i] == 0) break;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        subSetSum.assign(k, 0);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum % k != 0) return false;
        sort(nums.rbegin(), nums.rend());
        this->nums = nums;
        this->sum = totalSum / k;

        return dfs(0);
    }
};