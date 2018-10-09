class Solution {
private:
    bool flagDFS=true;
    vector<vector<bool>> flag;
public:
    bool isNext(int y, int x, int rowNum, int colNum, vector<vector<char>> board, string word, int len){
        if((0<=y&&y<rowNum)&&(0<=x&&x<colNum)){
            if((board[y][x]==word[len])&&(!flag[y][x])){
                return true;
            }
        }
        return false;
    }
    void wordDFS(vector<vector<char>>& board, string word, int y, int x, int rowNum, int colNum, bool& ans, int len){
        if(flagDFS){
            flag[y][x]=true;
            if(len==word.size()){
                ans=true;
                flagDFS=false;
                return;
            }
            if(isNext(y-1, x, rowNum, colNum, board, word, len)){
                wordDFS(board, word, y-1, x, rowNum, colNum, ans, len+1);
            }
            if(isNext(y+1, x, rowNum, colNum, board, word, len)){
                cout<<"y+1"<<endl;
                wordDFS(board, word, y+1, x, rowNum, colNum, ans, len+1);
            }
            if(isNext(y, x+1, rowNum, colNum, board, word, len)){
                cout<<"here"<<endl;
                wordDFS(board, word, y, x+1, rowNum, colNum, ans, len+1);
            }
            if(isNext(y, x-1, rowNum, colNum, board, word, len)){
                wordDFS(board, word, y, x-1, rowNum, colNum, ans, len+1);
            }
            flag[y][x]=false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int rowNum = board.size();
        if(!rowNum){
            return ans;
        }
        int colNum = board[0].size();
        for(int i=0; i<rowNum; i++){
            vector<bool> tmp(colNum, false);
            flag.push_back(tmp);
        }
        for(int i=0; i<rowNum; i++){
            if(ans){
                break;
            }
            for(int j=0; j<colNum; j++){
                if(ans){
                    break;
                }
                if(board[i][j]==word[0]){
                    flagDFS=true;
                    wordDFS(board, word, i, j, rowNum, colNum, ans, 1);
                }
            }
        }
        return ans;
    }
};