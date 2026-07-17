class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < m + n; i++){
            nums1[i] = nums2[i - m];
        }

        int p2 = m;

        while(p2 < nums1.size()){
            int p1 = 0;
            while(p1 <= p2){
                if(nums1[p1] > nums1[p2]){
                    swap(nums1[p1], nums1[p2]);
                }
                p1++;
            }
            p2++;
        }
        
    }
};