class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res= 0,cnt =0;
        for( int  i : nums){
            if(i==0){
                res = max(res,cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        return max(res,cnt);
    }
};