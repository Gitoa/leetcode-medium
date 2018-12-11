class Solution {
public:
    vector<vector<bool>> vis;
    bool isValid(int i, int j, int row, int col){
        return (0<=i && i<row) && (0<=j && j<col);
    }
    void bfs(pair<int, int> p, int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push(p);
        vis[p.first][p.second] = true;
        while(!q.empty()){
            pair<int, int> tmpP = q.front();
            q.pop();
            int i=tmpP.first, j=tmpP.second;
            if(isValid(i-1, j, row, col)&&!vis[i-1][j]){
                if(grid[i-1][j]=='1'){
                    pair<int, int> tmpPair(i-1, j);
                    q.push(tmpPair);
                    vis[i-1][j] = true;
                }
            }
            if(isValid(i+1, j, row, col)&&!vis[i+1][j]){
                if(grid[i+1][j]=='1'){
                    pair<int, int>tmpPair(i+1, j);
                    q.push(tmpPair);
                    vis[i+1][j] = true;
                }
            }
            if(isValid(i, j-1, row, col)&&!vis[i][j-1]){
                if(grid[i][j-1]=='1'){
                    pair<int, int>tmpPair(i, j-1);
                    q.push(tmpPair);
                    vis[i][j-1] = true;
                }
            }
            if(isValid(i, j+1, row, col)&&!vis[i][j+1]){
                if(grid[i][j+1]=='1'){
                    pair<int, int>tmpPair(i, j+1);
                    q.push(tmpPair);
                    vis[i][j+1] = true;
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0){
            return 0;
        }
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            vector<bool> tmp(col, false);
            vis.push_back(tmp);
        }
        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j] && (grid[i][j]=='1')){
                    ans ++;
                    pair<int, int> p(i, j);
                    bfs(p, row, col, grid);
                }
            }
        }
        return ans;
    }
};