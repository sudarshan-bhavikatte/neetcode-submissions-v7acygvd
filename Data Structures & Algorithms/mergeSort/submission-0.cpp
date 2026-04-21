// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
private:
    void merge(vector<Pair>& pairs, int s, int m, int e){
        int i = s;
        int j = m + 1;
        vector<Pair> temp;
        while(i <= m && j <= e){
            if(pairs[i].key <= pairs[j].key){
                temp.push_back(pairs[i]);
                i++;
            }
            else{
                temp.push_back(pairs[j]);
                j++;
            }
        }

        while(i<= m){
            temp.push_back(pairs[i]);
            i++;
        }

        while(j<= e){
            temp.push_back(pairs[j]);
            j++;
        }

        for(int i = s; i <= e; i++){
            pairs[i] = temp[ i - s];
        }
    }
    
    void helper(vector<Pair>& pairs, int s, int e){
        if(e - s + 1 <= 1)return;

        int m = s + (e - s) / 2;

        helper(pairs, s, m);
        helper(pairs, m + 1, e);

        merge(pairs, s, m, e);
    }
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        helper(pairs, 0, pairs.size() - 1);

        return pairs;
    }
};
