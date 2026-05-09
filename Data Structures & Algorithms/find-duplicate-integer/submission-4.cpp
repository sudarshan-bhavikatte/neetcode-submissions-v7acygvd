class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash;

        for(int n : nums){
            if(hash[n]) return n;
            hash[n] = true;
        }
    }
};
