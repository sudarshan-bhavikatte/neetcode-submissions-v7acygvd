class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        //brute force
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;O(n^2) space efficent

        //optimal O(n) time efficent

        unordered_map<int,bool> hash;

        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]])return true;
            hash[nums[i]] = true;
        }

        return false;

    }
};