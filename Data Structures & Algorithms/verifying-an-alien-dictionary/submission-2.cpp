class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;

        for(int i = 0; i < order.size(); i++)map[order[i]] = i;

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < i; j++){
                string first = words[i];
                string second = words[j];

                bool flag = false;
                for(int k = 0; k < min(first.size(), second.size()); k++){
                    if(map[first[k]] > map[second[k]]){
                        flag = true;
                        break;
                    }
                    else if (map[first[k]] < map[second[k]]) return false;
                }

                if(!flag && first.size() < second.size())return false;
            }
        }

        return true;
    }
};