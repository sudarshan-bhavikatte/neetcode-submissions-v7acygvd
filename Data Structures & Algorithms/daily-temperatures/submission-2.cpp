class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;

        for(int i = temperatures.size() - 1; i >= 0; i--){
            if(s.empty()){
                s.push({temperatures[i], 0});
                continue;
            }
            int k = 0;
            while(!s.empty() && s.top().first <= temperatures[i]){
                k += s.top().second;
                s.pop();
            }
            if(s.empty()){
                s.push({temperatures[i], 0});
            }
            else {
                res[i] = k + 1;
                s.push({temperatures[i], k+1});
            }
        }

        return res;
    }
};
