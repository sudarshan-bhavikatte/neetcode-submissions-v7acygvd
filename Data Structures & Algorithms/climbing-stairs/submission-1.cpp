class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int lastButOne = 1;
        
        if (n < 2)return 1;

        for(int i =0; i < n - 1; i++){
            int temp = lastButOne;

            lastButOne = lastButOne + last;
            last = temp;
        }

        return lastButOne;
    }
};
