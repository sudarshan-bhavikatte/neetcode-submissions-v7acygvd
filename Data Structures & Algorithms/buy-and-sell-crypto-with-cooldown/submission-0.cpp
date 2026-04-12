class Solution {
private:
    int dfs(int i, bool buying, vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }

        int cooldown = dfs(i+1, buying, prices);

        if(buying){
            int buy = dfs(i+1, false, prices) - prices[i] ;
            return std::max(cooldown, buy);
        } else {
            int sell = dfs(i+2, true, prices) + prices[i];
            return std::max(cooldown, sell);
        }

    }
public:
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);        
    }
};
