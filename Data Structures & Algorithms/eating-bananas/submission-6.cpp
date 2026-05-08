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

    for(int i = 1; i <= mx; i++) {

        long long time = 0;

        for(int p : piles) {
            time += (p + i - 1) / i;
        }

        if(time <= h) return i;
    }

    return 0;
}
};
