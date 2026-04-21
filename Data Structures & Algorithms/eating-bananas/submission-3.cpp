// k is eating rate
// can eat k bananas, if piles[i] < k, idle till next hour
// find min(k) so that call bananas can be eaten in h hours

// given:
// h >= piles.size

// if h == size => k = max(piles)
// h = sum(bananas) => k = 1

// hence => 1 <= k <= size

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = INT_MAX;

        int s = 1;
        
        int e = INT_MIN;
        for(int pile : piles)e = max(e, pile);

        while(s <= e){
            int m = (s + e) / 2;

            int time = 0;

            for(int pile : piles){
                time += (pile % m == 0) ? pile / m : (pile / m) + 1;
            }

            if(time <= h){
                k = min(k, m);
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }

        return k;
    }
};
