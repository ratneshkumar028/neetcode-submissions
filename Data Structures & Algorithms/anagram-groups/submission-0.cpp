class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> re;
        for( const auto& s : strs){
            string  n = s;
            sort(n.begin(),n.end());
            re[n].push_back(s);


        }
        vector<vector<string>> ans;
        for(auto& pair : re){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
