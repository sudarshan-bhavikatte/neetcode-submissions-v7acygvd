class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for(int n : nums){
            if(hash.find(n) == hash.end()){
                hash[n] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};