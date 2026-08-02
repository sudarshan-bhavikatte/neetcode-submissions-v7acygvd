class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int ast : asteroids){
            if(s.empty())s.push(ast);
            else if(ast < 0 && s.top() < 0 || ast > 0 && s.top() > 0 || ast > 0 && s.top() < 0){
                s.push(ast);
            }
            else {
                while(!s.empty() && ast < 0 && s.top() > 0 && abs(ast) > s.top()){
                    s.pop();
                }
                if(s.empty())s.push(ast);
                else if(!s.empty() && ast < 0 && s.top() < 0)s.push(ast);
                else if(!s.empty() && ast < 0 && s.top() > 0 && s.top() == abs(ast))s.pop();
            }
        }

        vector<int> res(s.size(), 0);

        int i = res.size() - 1;
        while(!s.empty()){
            res[i--] = s.top(); s.pop();
        }

        return res;
    }
};