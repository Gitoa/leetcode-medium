class Solution {
private:
    int ans=0;
    int dp[105][105]={0};
public:
    void dpPaths(){
        memset(dp, 0, sizeof(dp));
        dp[0][1]=1;
        for(int i=1; i<101; i++){
            for(int j=1; j<101; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    void pathDFS(int m, int n){
        if(m==0 || n==0){
            ans+=1;
        }else{
            pathDFS(m-1, n);
            pathDFS(m, n-1);
        }
    }
    int uniquePaths(int m, int n) {
        dpPaths();
        return dp[m][n];
    }
};