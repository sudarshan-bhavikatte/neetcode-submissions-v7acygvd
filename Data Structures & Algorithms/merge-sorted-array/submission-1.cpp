class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int j = 0; j < n; j++){
            int i = 0;

            while( i < m){
                if(nums1[i] > nums2[j])swap(nums1[i], nums2[j]);
                i++;
            }
            nums1[i] = nums2[j];
            m++;
        }
    }
};