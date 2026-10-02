class Solution {
    void mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return;
        int m = (s + e) / 2;
        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);

        merge(nums, s, m, e); 
    }

    void merge(vector<int>& nums, int s, int m, int e){
        vector<int> temp;
        int i = s;
        int j = m + 1;
        while(i <= m && j <= e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m)temp.push_back(nums[i++]);
        while(j <= e)temp.push_back(nums[j++]);

        for(int k = s; k <= e; k++){
            nums[k] = temp[k - s];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        mergeSort(nums, i, j);

        return nums;
    }
};