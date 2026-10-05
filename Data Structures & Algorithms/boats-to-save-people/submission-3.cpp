class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int l = 0;
        int r = people.size() - 1;

        while(l <= r){
            int w = people[l] + people[r];
            if(l < r && w <= limit){
                l++;
                r--;
                boats++;
            } else{
                r--;
                boats++;
            }
        }

        return boats;
    }
};