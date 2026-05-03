class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> hash;
        
        for(int num : nums)hash[num]++;

        for(auto it = hash.begin(); it != hash.end(); it++){
            if(it->second > n)return it->first;
        }

        return 0;
    }
};