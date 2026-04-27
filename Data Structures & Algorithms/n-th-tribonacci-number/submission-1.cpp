class Solution {
    unordered_map<int, int> memo;
    int helper(int n){
        if(memo.find(n) != memo.end())return memo[n];
        if(n == 0)return 0;
        if(n == 1 || n == 2)return 1;

        memo[n] = helper(n - 3) + helper(n - 2) + helper(n - 1);
        return memo[n];
    }
public:
    int tribonacci(int n) {
        return helper(n);
    }
};