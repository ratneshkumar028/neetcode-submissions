class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for( int i =0;i<n;i++){
            for( int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int i,int j){
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || grid[i][j]=='0' ){
            return;
        }
        grid[i][j]='0';
        for( int k =0;k<4;k++){
            dfs(grid,i+dir[k][0],j+dir[k][1]);
        }
    }
};
