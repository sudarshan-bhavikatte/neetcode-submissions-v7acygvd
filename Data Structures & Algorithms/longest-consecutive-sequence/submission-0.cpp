class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for(int n : nums){
            if(!set.count(n-1)){\
                int curr = n;
                int count = 1;

                while(set.count(curr+1)){
                    curr++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
