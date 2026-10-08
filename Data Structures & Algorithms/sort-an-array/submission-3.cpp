class Solution {
    void mergeSort(vector<int>& nums, int s, int e){
        if(s >= e)return;
        int m = (s + e) / 2;
        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);
        merge(nums, s, m, e);
    }

    void merge(vector<int>& nums, int s, int m, int e){
        vector<int> temp;

        int p1 = s;
        int p2 = m + 1;

        while(p1 <= m && p2 <= e){
            if(nums[p1] <= nums[p2]){
                temp.push_back(nums[p1]);
                p1++;
            } else {
                temp.push_back(nums[p2]);
                p2++;
            }
        }

        while(p1 <= m){
            temp.push_back(nums[p1]);
            p1++;
        }
        while(p2 <= e){
            temp.push_back(nums[p2]);
            p2++;
        }

        for(int i = s; i <= e; i++){
            nums[i] = temp[i - s];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};