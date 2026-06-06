class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int ans = 1;
        int len = 1;
        int prevCmp = 0;

        for (int i = 1; i < n; i++) {
            int cmp = 0;

            if (arr[i] > arr[i - 1]) cmp = 1;
            else if (arr[i] < arr[i - 1]) cmp = -1;

            if (cmp == 0) {
                len = 1;
            }
            else if (cmp * prevCmp == -1) {
                len++;
            }
            else {
                len = 2;
            }

            ans = max(ans, len);
            prevCmp = cmp;
        }

        return ans;
    }
};