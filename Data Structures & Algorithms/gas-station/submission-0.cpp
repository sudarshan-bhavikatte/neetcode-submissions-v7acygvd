class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);

        if(total_cost > total_gas)return -1;

        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;

    }
};
