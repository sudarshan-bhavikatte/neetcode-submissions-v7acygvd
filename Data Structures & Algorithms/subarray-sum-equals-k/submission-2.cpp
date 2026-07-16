class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;

        for(int n : nums){
            curSum += n;
            int diff = curSum - k;
            if(hash.find(diff) != hash.end()){
                res += hash[diff];
            }
            hash[curSum]++;
        }

        return res;
    }
};