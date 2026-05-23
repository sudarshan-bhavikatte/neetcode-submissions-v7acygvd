class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int, bool> map;

        map[n] = true;

        while(n != 1){
            int sum = 0;
            
            while(n > 0){
                int r = n % 10;
                sum += (r * r);
                n /= 10;
            }

            if(map[sum]) return false;

            map[sum] = true;

            n = sum;
        }

        return true;
    }
};
