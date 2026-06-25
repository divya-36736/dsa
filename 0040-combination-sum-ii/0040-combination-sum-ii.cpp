class Solution {
public:
    void solve(int i, int target, vector<int>& candidates,
               set<vector<int>>& ans, vector<int>& res) {

        if (target == 0) {
            ans.insert(res);
            return;
        }

        int n = candidates.size();

        for (int j = i; j < n; j++) {

            // Skip duplicates
            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            // Since array is sorted
            if (candidates[j] > target)
                break;

            res.push_back(candidates[j]);

            solve(j + 1, target - candidates[j], candidates, ans, res);

            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        set<vector<int>> ans;
        vector<int> res;

        solve(0, target, candidates, ans, res);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};