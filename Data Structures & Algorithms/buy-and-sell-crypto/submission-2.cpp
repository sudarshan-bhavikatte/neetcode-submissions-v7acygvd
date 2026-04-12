class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int netProfit = 0;

    //   for(int i=0;i<prices.size()-1;i++){
    //     for(int j=i+1;j<prices.size();j++){
    //         int diff = prices[j] - prices[i];
    //         netProfit = max(diff,netProfit);  
    //     }
    //   }  

    int left = 0;
    int right = 1;

    while(right<prices.size()){
        if(prices[left] < prices[right]){
            int diff = prices[right] - prices[left];
            netProfit = max(diff,netProfit);
        }
        else {
           left = right;
        }
        right++;
    }


      return netProfit;
    }
};
