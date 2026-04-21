class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        sort(points.begin(), points.end(), [](vector<int> a, vector<int>b){
            int a_dis = (a[0] * a[0]) + (a[1] * a[1]);
            int b_dis = (b[0] * b[0]) + (b[1] * b[1]);

            return a_dis < b_dis;
        });

        int i = 0;
        while (i < k){
            res.push_back(points[i]);
            i++;
        }

        return res;
    }
};
