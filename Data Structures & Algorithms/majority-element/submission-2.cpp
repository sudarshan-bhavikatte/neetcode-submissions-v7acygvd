class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int need = nums.size() / 2;

        unordered_map<int, int> count;

        for(int n : nums){
            count[n]++;
            if(count[n] > need)return n;
        }

        return 0;
    }
};