/*
    array piles where piles[i] is the number of bananas in the ith pile
    h, which represents the number of hours you have to eat all the bananas.

    You may decide your bananas-per-hour eating rate of k.
    Return the minimum integer k such that you can eat all the bananas within h hours
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int mx = *max_element(piles.begin(), piles.end());
    
    int i = 1;
    int j = mx;
    int res = INT_MAX;
    while(i <= j) {
        int m = (i + j) / 2;
        long long time = 0;

        for(int p : piles) {
            time += (p + m - 1) / m;
        }

        if(time <= h){
            res = min(res, m);
            j = m - 1;
        }
        else if(time > h) i = m + 1;
    }

    return res;
}
};
