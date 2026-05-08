/*
    must be shipped from one port to another within days days.
    The ith package on the conveyor belt has a weight of weights[i].
    Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
    It is not allowed to load weight more than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages 
    on the conveyor belt being shipped within days days.
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res = INT_MAX;

        while(l <= r){
            int m = (r + l) / 2;
            int d = 1;
            int tw = 0;
            for(int w : weights){
                if(tw + w > m){
                    d++;
                    tw = 0;
                }
                tw += w;
            }
            if(d <= days){
                res = min(res, m);
                r = m - 1;
            }
            else if(d > days){
                l = m + 1; 
            }
        }

        return res;
    }
};