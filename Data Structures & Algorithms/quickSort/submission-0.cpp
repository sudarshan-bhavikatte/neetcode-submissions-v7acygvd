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
    void helper(vector<Pair>& pairs, int s, int e){
    if (s >= e) return;

    int pivot = pairs[e].key;
    int left = s;

    for(int i = s; i < e; i++){
        if(pairs[i].key < pivot){
            swap(pairs[i], pairs[left]);
            left++;
        }
    }

    swap(pairs[left], pairs[e]);

    helper(pairs, s, left - 1);
    helper(pairs, left + 1, e);
}
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {

        helper(pairs, 0, pairs.size() - 1);
        return pairs;            
    }
};
