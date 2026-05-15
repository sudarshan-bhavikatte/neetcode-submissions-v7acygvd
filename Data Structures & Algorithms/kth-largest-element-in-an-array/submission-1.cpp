class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [](const int &a, const int &b){
            return a < b;
        };
        priority_queue<
            int,
            vector<int>,
            decltype(comp)
        > pq(comp);

        for(int n : nums)pq.push(n);

        while(k > 1){
            pq.pop(); k --;
        }

        return pq.top();
    }
};
