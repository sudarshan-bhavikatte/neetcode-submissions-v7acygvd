class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;

        for(int i = 0; i < numbers.size(); i++){
            if(hash.find(numbers[i]) != hash.end()){
                return {hash[numbers[i]] + 1, i + 1};
            }
            hash[target - numbers[i]] = i;
        }
        return {};
    }
};
