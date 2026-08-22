class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp = prices;

            for(auto flight : flights){
                int f = flight[0];
                int t = flight[1];
                int p = flight[2];
                if (prices[f] == INT_MAX){
                    continue;
                }
                else if (prices[f] + p < temp[t]){
                    temp[t] = prices[f] + p;
                }
            }

            prices = temp;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
