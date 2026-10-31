class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for (auto num : nums) {

            if (ans.empty() || ans.back()[1] < num[0]) {
                ans.push_back(num);
            }
            else {
                ans.back()[1] = max(ans.back()[1], num[1]);
            }
        }
        
        return ans;
    }
};