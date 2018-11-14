class Solution {
private:
    vector<vector<bool>> flag;
public:
    void dfs(int i, int j, int row, int col, vector<vector<char>>& board){
        if(i<1 || i>row-2){
            return;
        }
        if(j<1 || j>col-2){
            return;
        }
        if(flag[i][j] == true || board[i][j] != 'O'){
            return;
        }
        flag[i][j] = true;
        dfs(i-1, j, row, col, board);
        dfs(i+1, j, row, col, board);
        dfs(i, j-1, row, col, board);
        dfs(i, j+1, row, col, board);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row<=2){
            return;
        }
        int col = board[0].size();
        if(col<=2){
            return;
        }
        for(int i=0; i<row; i++){
            vector<bool> flagRow(col, false);
            flag.push_back(flagRow);
        }
        
        for(int i=1; i<col-1; i++){
            if(board[0][i] == 'O'){
                dfs(1, i, row, col, board);
            }
            if(board[row-1][i] == 'O'){
                dfs(row-2, i, row, col, board);
            }
        }
        for(int i=1; i<row-1; i++){
            if(board[i][0] == 'O'){
                dfs(i, 1, row, col, board);
            }
            if(board[i][col-1] == 'O'){
                dfs(i, col-2, row, col, board);
            }
        }
        for(int i=1; i<row-1; i++){
            for(int j=1; j<col-1; j++){
                if(board[i][j] == 'O' && flag[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};