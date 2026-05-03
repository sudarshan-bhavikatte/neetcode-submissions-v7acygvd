class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for(auto i : intervals){
            int start = i[0];
            int end = i[1];
            int lastEnd = output.back()[1];

            if(start <= lastEnd){
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
            
        }
        return output;
    }
};
