/*
    arr asteriods:
        idx -> pos
        abs(val) -> size
        sign = direction -> + = right
        
    if a and b collide:
        if a < b : a is destroyed
        if a == b : both destroyed
        if (a_sign == b_sign) never collide
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int a : asteroids){
            int dir = a / abs(a);
            if(s.empty()){
                s.push(a);
                continue;
            }
            if(dir == 1){
                s.push(a);
                continue;
            }
            bool flag = true;
            while(!s.empty() && (s.top() / abs(s.top()) != dir)){
                int b = s.top();
                if(abs(a) < abs(b)){
                    flag = false;
                    break;
                }
                else if(abs(a) > abs(b)){
                    s.pop();
                }
                else {
                    s.pop();
                    flag = false;
                    break;
                }
            }
            if(flag) s.push(a);
        }
        vector<int> res(s.size(), 0);

        while(!s.empty()){
            res[s.size() - 1] = s.top();
            s.pop();
        }
        return res;
    }
};