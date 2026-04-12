class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int pq_size = 0;
        for(int i=0;i<nums.size();i++){
            if(pq_size < k){
                pq.push(nums[i]);
                pq_size++;
                continue;
            }
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }        
        return pq.top();
    }
};
