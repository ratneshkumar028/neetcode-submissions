class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>scotr(n+1,0);
        for( auto t: trust)
        {
            int a = t[0];
            int b= t[1];
            scotr[a]--;
            scotr[b]++;


        }
        for( int i =1;i<=n;i++){
            if(scotr[i]==n-1){
                return i;
            }
        }
        return -1;

    }
};