class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int n : nums){
            if(s.count(n - 1)) continue;

            int len = 1;
            while(s.count(n + len))len++;

            res = max(res, len);
        }

        return res;
    }
};
