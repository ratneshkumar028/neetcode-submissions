class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int num : nums){
            mpp[num]++;
        }
        vector<pair<int,int>> ans;
        for(auto it: mpp ){
            ans.push_back({it.second,it.first});
        }
        sort(ans.rbegin(),ans.rend());
        vector<int> re;
        for(int i =0;i<k;i++){
            re.push_back(ans[i].second);
        }
        return re;

    }
};
