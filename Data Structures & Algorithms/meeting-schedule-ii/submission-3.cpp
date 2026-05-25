/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        
        auto sort_func = [&](Interval& a,Interval& b){
            return a.start < b.start;
        };
        auto heap_func = [&](Interval& a, Interval& b){
            return b.end < a.end;
        };

        sort(intervals.begin(), intervals.end(), sort_func);
        
        priority_queue<Interval, vector<Interval>, decltype(heap_func) > pq(heap_func);
        pq.push(intervals[0]);
        int res = 1;

        for(int i = 1; i < intervals.size(); i++){
            Interval curr = intervals[i];
            if(curr.start < pq.top().end){
                pq.push(curr);
            }
            else {
                while(!pq.empty() && curr.start >= pq.top().end){
                    pq.pop();
                }
                pq.push(curr);
            }
            res = max(res, (int)pq.size());
        }

        return res;
        
    }
};
