class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > curr) {
                res += (prices[i] - curr);
            }
            curr = prices[i];
        }

        return res;
    }
};