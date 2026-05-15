class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hash;
        for(char c : s)hash[c]++;

        auto func = [&](const pair<char, int> a, const pair<char, int> b){
            return a.second < b.second;
        };

        priority_queue<
            pair<char, int>,
            vector<pair<char, int>>,
            decltype(func)
        > pq(func);

        for(auto it = hash.begin(); it != hash.end(); it++)pq.push({it->first, it->second});

        string res;

        while(!pq.empty()){
            auto [c, cnt] = pq.top();

            if(res.size() == 0){
                res += c;
                pq.pop();
                if (cnt - 1 > 0){
                    pq.push({c, cnt - 1});
                }
            }
            else {
                if(res[res.size() - 1] == c){
                    pair<char, int> temp;
                    temp = pq.top(); pq.pop();
                    if(pq.empty())return "";
                    auto [c1, cnt2] = pq.top(); pq.pop();
                    res += c1;
                    if(cnt2 - 1 > 0){
                        pq.push({c1, cnt2 - 1});
                    }
                    pq.push(temp);
                }
                else {
                    res += c;
                pq.pop();
                if (cnt - 1 > 0){
                    pq.push({c, cnt - 1});
                }
                }
            }

        }

        return res;

    }
};