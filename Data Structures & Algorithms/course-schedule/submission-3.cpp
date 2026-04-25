class Solution {
    unordered_map<int, vector<int>> pre_req;

    bool dfs(int course, unordered_set<int>& V) {
        if (V.count(course)) return false;

        V.insert(course);

        for (int p : pre_req[course]) {
            if (!dfs(p, V)) return false;
        }
        V.erase(course);

        return true;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto p : prerequisites) {
            pre_req[p[0]].push_back(p[1]);
        }

        unordered_set<int> V;

        for (int i = 0; i < numCourses; i++) {
            V.insert(i);

            for (int p : pre_req[i]) {
                if (!dfs(p, V)) return false;
            }
            V.erase(i);
        }

        return true;
    }
};
