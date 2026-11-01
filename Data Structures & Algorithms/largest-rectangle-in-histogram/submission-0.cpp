class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
       int n =  nums.size();
       int m = 0;
       stack<int>st;
       for(int i = 0; i <= n; i++){
            while (!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int h = nums[st.top()];
                st.pop();
                int w = st.empty()? i : i-st.top()-1;
                m = max(m,h*w);
            }
            st.push(i);
       }
       return m;


    }
};
