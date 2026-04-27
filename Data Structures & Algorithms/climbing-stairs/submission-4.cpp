// there are n steps
// each step can be (n-1) or (n-2)
// return number of ways

// when n == 0 its one way

class Solution {
    int res = 0;
    unordered_map<int, int> memo;

    int helper(int n){
        if(memo.find(n) != memo.end()) return memo[n];
        if(n <= 1)return 1;

        memo[n] = helper(n - 1) + helper(n - 2); 
        return memo[n];
    }

public:
    int climbStairs(int n) {
        return helper(n);
    }
};
