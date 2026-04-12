class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;

        while (l < r){
            int m = (l+r)/2;
            if(nums[m] > nums[r]){
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        int pivot = l;

        int res = binarySearch(nums, 0, l-1, target);
        if (res != -1){
            return res;
        }

        return binarySearch(nums, l, nums.size()-1, target);
    }

    int binarySearch(vector<int>& nums, int s, int e, int target){
        int l = s;
        int r = e;
        while (l<=r){
            int m = (l+r)/2;

            if(nums[m] == target)return m;
            else if (nums[m] > target)r= m-1;
            else l = m+1;
        }
        return -1;
    }
};
