class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> st;

        for(string op : ops){
            if(op[0] == '+'){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();   
                st.push(a);
                st.push(b);     
                st.push(a + b);
            } else if(op[0] == 'C'){
                st.pop();
            } else if(op[0] == 'D'){
                st.push(st.top() * 2);
            } else {
                st.push(stoi(op));
            }
        }

        int res = 0;

        while(!st.empty()){
            res += st.top(); st.pop();
        }

        return res;
    }
};