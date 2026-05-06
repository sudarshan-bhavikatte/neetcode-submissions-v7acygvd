class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;

        int i = 0;
        int j = people.size() - 1;

        while(i <= j){
            int total = people[i] + people[j];
            cout << people[i] << " " << people[j] << endl;
            if(total <= limit){
                res++;
                i++;
                j--;
            }
            else{
                res++;
                j--;
            }
        }

        return res;
    }
};