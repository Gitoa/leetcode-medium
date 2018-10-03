class Solution {
private:
    int pathDFS[105][105];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(pathDFS, 0, sizeof(pathDFS));
        pathDFS[0][1]=1;
        int len=obstacleGrid.size();
        if(!len){
            return 0;
        }
        int lenSec=obstacleGrid[0].size();
        for(int i=1; i<=len; i++){
            for(int j=1; j<=lenSec; j++){
                if(obstacleGrid[i-1][j-1]==0){
                    pathDFS[i][j]=pathDFS[i-1][j]+pathDFS[i][j-1];
                }
                else{
                    pathDFS[i][j]=0;
                }
            }
        }
        return pathDFS[len][lenSec];
    }
};