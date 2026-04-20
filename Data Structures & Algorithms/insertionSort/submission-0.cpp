// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();

        vector<vector<Pair>> res;
        for(int i = 0; i < n; i++){
            
            int j = i - 1;
            while(j >= 0 && pairs[j + 1].key < pairs[j].key){
                swap(pairs[j+1], pairs[j]);
                j--;
            }
            res.push_back(pairs);
        }

        return res;
    }
};
