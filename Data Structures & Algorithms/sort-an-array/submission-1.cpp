class Solution {

    void merge_sort(int s, int e, vector<int>& nums){
        if(e <= s) return;
        int m = (s + e) / 2;
        merge_sort(s, m, nums);
        merge_sort(m + 1, e, nums);
        merge(s, m, e, nums);
    }

    void merge(int s, int m, int e, vector<int>& nums){
        int i = s;
        int j = m + 1;
        vector<int> temp;
        while(i <= m && j <= e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= e){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = s; k <= e; k++){
            nums[k] = temp[k - s];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0, nums.size() - 1, nums);
        return nums;
    }
};