class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);

        // Exclude current element
        temp.pop_back();
        solve(idx + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};