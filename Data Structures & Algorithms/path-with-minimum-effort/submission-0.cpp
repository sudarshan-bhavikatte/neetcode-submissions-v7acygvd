class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int diff = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(row == rows - 1 && col == cols - 1)return diff;
            if(dist[row][col] < diff)continue;

            for(vector<int> move : moves){
                int newR = row + move[0];
                int newC = col + move[1];
                if (newR < 0 || newC < 0 || newR >= rows || newC >= cols) {
                    continue;
                }

                int newDiff = max(diff, abs(heights[row][col] - heights[newR][newC]));
                if(newDiff < dist[newR][newC]){
                    dist[newR][newC] = newDiff;
                    pq.push({newDiff, newR, newC});
                }
            }
        }
        return 0;
    }
};