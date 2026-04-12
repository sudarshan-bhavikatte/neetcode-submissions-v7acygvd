class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(),0);
        vector<pair<int,int>> stack;

        for(int i=0; i<temp.size(); i++){
            int t = temp[i];

            while(!stack.empty() && t > stack.back().first){
                auto pair = stack.back();
                stack.pop_back();
                res[pair.second] = i - pair.second;
            }
            stack.push_back({t,i});
        }
        return res;
    }
};
