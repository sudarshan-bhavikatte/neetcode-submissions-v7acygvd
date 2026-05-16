class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> params = {{}};

        for(int n : nums){
            vector<vector<int>> new_params;
            for(auto p : params){
                for(int i = 0; i <= p.size(); i++){
                    vector<int> copy = p;
                    copy.insert(copy.begin() + i, n);
                    new_params.push_back(copy);
                }
            }
            params = new_params;
        }            
        return params;
    }
};
