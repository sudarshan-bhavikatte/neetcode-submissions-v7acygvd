class KthLargest {
    int K;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;

        for(int n : nums)pq.push(n);
    }
    
    int add(int val) {
        pq.push(val);
        int k = K;
        vector<int> temp;
        int res = 0;
        while(k > 1){
            temp.push_back(pq.top()); pq.pop();
            k--;
        }
        res = pq.top();

        for(int t : temp)pq.push(t);

        return res;
    }
};
