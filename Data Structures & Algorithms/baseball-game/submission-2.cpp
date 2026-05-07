class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(string op : operations){
            if(op == "+"){
                vector<int> temp(3, 0);
                temp[1] = s.top(); s.pop();
                temp[0] = s.top(); s.pop();
                temp[2] = temp[0] + temp[1];

                for(int n : temp)s.push(n);
            }
            else if(op == "D"){
                int n = s.top();
                s.push(n * 2);
            }
            else if (op == "C"){
                s.pop();
            }
            else {
                int n = std::stoi(op);
                s.push(n);
            }
        }

        int res = 0;
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        return res;
    }
};