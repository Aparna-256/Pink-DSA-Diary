class Solution {
public:
    void solve(vector<string>& nums,
               vector<string>& curr,
               vector<vector<string>>& ans,
               int index) {

        // base case
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // include
        curr.push_back(nums[index]);
        solve(nums, curr, ans, index + 1);

        // backtrack
        curr.pop_back();

        // exclude
        solve(nums, curr, ans, index + 1);
    }

    vector<vector<string>> Power_set(vector<string>& nums) {
        vector<string> curr;
        vector<vector<string>> ans;

        solve(nums, curr, ans, 0);
        return ans;
    }
};
