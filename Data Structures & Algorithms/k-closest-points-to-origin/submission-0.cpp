class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        priority_queue<
            pair<float, pair<int,int>>,
            vector<pair<float, pair<int,int>>>,
            greater<pair<float, pair<int,int>>>
            > pq;
        
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            float dis = sqrt((x*x) + (y*y));

            pq.push({dis,{x,y}});
        }

        for(int i =0;i<k;i++){
            if(pq.empty())break;

            pair<int,int> point = pq.top().second;
            pq.pop();
            res.push_back({point.first,point.second});
        }

        return res;
    }
};
