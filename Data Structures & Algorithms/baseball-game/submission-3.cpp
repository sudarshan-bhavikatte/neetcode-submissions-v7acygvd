class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(string op : operations){
            if(op == "+"){
                int a = s.top(); s.pop();
                int n = s.top() + a;
                s.push(a);
                s.push(n);
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