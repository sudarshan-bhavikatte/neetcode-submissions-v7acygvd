class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto func = [&](vector<int> a, vector<int> b){
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), func);

        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            vector<int> last = output.back();

            if(intervals[i][0] <= last[1]){
                output.pop_back();
                output.push_back({last[0], max(last[1], intervals[i][1])});
            }
            else {
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};
