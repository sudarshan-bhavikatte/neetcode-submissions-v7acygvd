class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if(visit.count("0000"))return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");
        while(!q.empty()){
            auto [code, turns] = q.front();
            q.pop();

            if(code == target)return turns;

            vector<string> children;

            for(int i = 0; i < 4; i++){
                string child = code;
                child[i] = (child[i] - '0' + 1) % 10 + '0';
                children.push_back(child);
                child = code;
                child[i] = (child[i] - '0' - 1 + 10) % 10 + '0';
                children.push_back(child);
            }

            for(string child : children){
                if(!visit.count(child)){
                    visit.insert(child);
                    q.push({child, turns + 1});
                }
            }
        }

        return -1;
    }
};