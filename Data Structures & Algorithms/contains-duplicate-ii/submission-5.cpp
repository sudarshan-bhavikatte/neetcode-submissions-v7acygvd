class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        bool res = false;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];

            if(hash.find(n) != hash.end()){
                res = (i - hash[n]) <= k;
            }
            hash[n] = i;
        }

        return res;
    }
};