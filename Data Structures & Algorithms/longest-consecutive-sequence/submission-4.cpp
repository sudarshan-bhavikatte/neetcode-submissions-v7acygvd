class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;

        unordered_set<int> set;

        for(int n : nums)set.insert(n);

        for(int n : nums){
            if(!set.count(n - 1)){
                int curr = 1;
                int num = n;
                set.erase(n);
                while(set.count(num + 1)){
                    set.erase(num);
                    curr++;
                    num++;
                }

                res = max(res, curr);
            }
        }

        return res;
    }
};
