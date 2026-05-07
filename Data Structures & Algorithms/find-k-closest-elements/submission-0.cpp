/*
    1. arr is sorted
    2. find k closet numbers to k
    3. sort the output

    if a is closer to x then b if : 
        abs(a - x) < abs(b - x) or abs(a - x) = abs(b - x) and a < b
    
    can do : 
        maintain a map for closet elements
        add them to a res vector
    
    edge cases:
        if x < nums[0]: return first k elements
        if x > nums.back() return last k elements
        if in between elements to the end have longest distance and reduces from there
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;

        if(x <= arr[0]){
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        if (x >= arr.back()){
            return vector<int>(arr.begin() + (arr.size() - k), arr.end());
        }
        map<int, multiset<int>> hash;
        
        for(int n : arr){
            hash[abs(n - x)].insert(n);
        }

        for(auto it = hash.begin(); it != hash.end(); it++){
            for(int x : it->second){
                if(res.size() <= k)res.push_back(x);
                if(res.size() == k){
                    sort(res.begin(), res.end());
                    return res;
                }
            }
        }
        return {};
    }
};