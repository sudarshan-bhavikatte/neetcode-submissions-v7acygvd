class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);

        for(int n : nums)v[n]++;
        nums.clear();
        for(int i = 0; i < 3; i++){
            int k = v[i];
            while(k > 0){
                nums.push_back(i);
                k--;
            }
        }
    }
};