// there are n steps
// each step can be (n-1) or (n-2)
// return number of ways

// when n == 0 its one way

class Solution {

public:
    int climbStairs(int n) {
        int a = 1; int b = 1;

        for(int i = 2; i < n + 1; i++){
            int temp = a + b;
            a = b;
            b = temp;
        }

        return b;
    }
};
