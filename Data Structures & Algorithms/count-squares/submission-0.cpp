class CountSquares {
    vector<vector<int>> points;
    unordered_map<string, int> map;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        string key = to_string(point[0]) + "#" + to_string(point[1]);
        map[key]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int res = 0;
        for(vector<int> p : points){
            
            int x1 = p[0];
            int y1 = p[1];

            if(abs(x - x1) != abs(y - y1) || x == x1 || y == y1)continue;

            string key1 = to_string(x) + "#" + to_string(y1);
            string key2 = to_string(x1) + "#" + to_string(y);

            res += map[key1] * map[key2];
        }

        return res;
    }
};
