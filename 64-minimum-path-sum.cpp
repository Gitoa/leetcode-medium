class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(!row){
            return 0;
        }
        int col=grid[0].size();
        vector<vector<int>> dp;
        for(int i=0; i<=row; i++){
            vector<int>tmp(col+1, 0);
            dp.push_back(tmp);
        }
        for(int j=1; j<col+1; j++){
            dp[1][j]=grid[0][j-1]+dp[1][j-1];
        }
        for(int j=1; j<row+1; j++){
            dp[j][1]=grid[j-1][0]+dp[j-1][1];
        }
        for(int i=2; i<=row; i++){
            for(int j=2; j<=col; j++){
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[row][col];
    }
};