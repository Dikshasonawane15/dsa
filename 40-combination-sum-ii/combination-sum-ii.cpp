class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int idx, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue; // Skip duplicates

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates);
        return ans;
    }
};