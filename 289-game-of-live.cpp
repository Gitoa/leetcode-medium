class Solution {
public:
    bool isValid(int i, int j, int row, int col){
        if((0<=i && i<row) && (0<=j && j<col)){
            return true;
        }
        return false;
    }
    void addNeighbor(int i, int j, int row, int col, vector<vector<int>>& liveNeighbor){
        if(isValid(i-1, j-1, row, col)){
            liveNeighbor[i-1][j-1]++;
        }
        if(isValid(i-1, j, row, col)){
            liveNeighbor[i-1][j]++;
        }
        if(isValid(i-1, j+1, row, col)){
            liveNeighbor[i-1][j+1]++;
        }
        if(isValid(i, j-1, row, col)){
            liveNeighbor[i][j-1]++;
        }
        if(isValid(i, j+1, row, col)){
            liveNeighbor[i][j+1]++;
        }
        if(isValid(i+1, j-1, row, col)){
            liveNeighbor[i+1][j-1]++;
        }
        if(isValid(i+1, j, row, col)){
            liveNeighbor[i+1][j]++;
        }
        if(isValid(i+1, j+1, row, col)){
            liveNeighbor[i+1][j+1]++;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> liveNeighbor;
        int row = board.size();
        if(row == 0){
            return;
        }
        int col = board[0].size();
        for(int i=0; i<row; i++){
            vector<int> tmp(col, 0);
            liveNeighbor.push_back(tmp);
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]==1){
                    addNeighbor(i, j, row, col, liveNeighbor);
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]==1 && liveNeighbor[i][j]<2){
                    board[i][j] = 0;
                }
                if(board[i][j]==1 && liveNeighbor[i][j]>3){
                    board[i][j] = 0;
                }
                if(board[i][j]==0 && liveNeighbor[i][j]==3){
                    board[i][j]=1;
                }
            }
        }
    }
};