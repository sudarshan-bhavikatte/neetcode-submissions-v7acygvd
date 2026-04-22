#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    queue<int> q;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        queue<int> temp;

        // Insert in ascending order
        while (!q.empty() && q.front() < val) {
            temp.push(q.front());
            q.pop();
        }

        temp.push(val);

        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        q = temp;

        // Keep only k largest elements
        while (q.size() > k) {
            q.pop(); // removes smallest
        }

        return q.front(); // kth largest
    }
};