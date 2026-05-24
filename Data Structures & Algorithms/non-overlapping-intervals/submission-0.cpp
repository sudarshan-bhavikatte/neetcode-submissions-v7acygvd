class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto func = [&](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), func);
        int res = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < prevEnd){
                res++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }

        return res;
    }
};
