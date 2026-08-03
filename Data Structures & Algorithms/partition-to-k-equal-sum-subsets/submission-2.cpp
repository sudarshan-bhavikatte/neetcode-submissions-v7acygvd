class Solution {
public:
    int target;
    vector<bool> visited;

    bool dfs(vector<int>& nums, int start, int currSum, int formed, int k) {
        // Successfully formed k - 1 subsets
        if (formed == k - 1)
            return true;

        // Current subset is complete, start building the next one
        if (currSum == target)
            return dfs(nums, 0, 0, formed + 1, k);

        for (int i = start; i < nums.size(); i++) {
            if (visited[i])
                continue;

            if (currSum + nums[i] > target)
                continue;

            visited[i] = true;

            if (dfs(nums, i + 1, currSum + nums[i], formed, k))
                return true;

            visited[i] = false;

            // Pruning:
            // If this was the first element of the current subset and it
            // didn't work, no need to try other choices in this position.
            if (currSum == 0)
                return false;

            // Skip duplicates
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0)
            return false;

        target = total / k;

        sort(nums.rbegin(), nums.rend());

        // Largest element cannot fit
        if (nums[0] > target)
            return false;

        visited.assign(nums.size(), false);

        return dfs(nums, 0, 0, 0, k);
    }
};