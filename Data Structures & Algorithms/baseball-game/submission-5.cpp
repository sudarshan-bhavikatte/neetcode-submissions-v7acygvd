class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(string str : operations){
            if(str == "+"){
                int a = s.top(); s.pop(); 
                int b = s.top(); s.pop();
                s.push(b); s.push(a);

                s.push(a + b);            
            }
            else if(str == "D"){
                int a = s.top();
                s.push(a * 2);            
    
            }
            else if(str == "C"){
                s.pop();
            }
            else {
                s.push(stoi(str));
            }
        }
        int res = 0;

        while(!s.empty()){
            res += s.top(); s.pop();
        }
        return res;
    }
};