class Solution {
    unordered_map<int, double> map;

    double pos_helper(double x, int n){
        if(map.find(n) != map.end())return map[n];
        if(n == 1) return x;

        if(n % 2 != 0){
            map[n] = pow(x, n/2) * pow(x, n/2 + 1);
        }
        else {
            map[n] = pow(x, n/2) * pow(x, n/2);

        }
        return map[n];
    }


public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n > 0) return pos_helper(x,n);
        if(n < 0) return 1 / pos_helper(x, n * -1);
    }
};
