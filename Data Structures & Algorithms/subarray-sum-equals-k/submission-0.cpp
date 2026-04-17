class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0;
        
        int total = 0;
        hash[total]++;

        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            if(hash.find(total - k) != hash.end()){
                res += hash[total - k];
            }
            hash[total]++;
        }      

        return res;
    }
};