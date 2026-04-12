class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = piles[0];
        for (int i=1;i<piles.size();i++){
            if (piles[i] > max)max = piles[i];
        }
        int res = max;

        while (min <=max){
            int k = (min + max)/2;
            int time = 0;

            for (int p : piles){
                time += ceil((double)(p)/k);
            }

            if(time <=h){
                res = k;
                max = k - 1;
            }
            else {
                min = k+1;
            }
        }
        return res;
    }
};