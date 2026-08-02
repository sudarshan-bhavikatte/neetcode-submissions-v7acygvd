class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> map;

        for(int i = 0; i < position.size(); i++){
            map[position[i]] = speed[i];
        }

        stack<float> s;
        sort(position.rbegin(), position.rend());

        for(int p : position){
            int dis = target - p;
            int sp = map[p];
            float time = (float)dis / (float)sp;            
            
            if(s.empty()){
                s.push(time);
            } else {
                if(s.top() < time)s.push(time);
            }
        }

        return s.size();
    }
};
