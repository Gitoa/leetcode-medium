class Solution {
public:
    bool isValidRow(vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            map<char, bool>m;
            vector<char> tmp = board[i];
            for(int j=0; j<9; j++){
                if(tmp[j]!='.' && m.count(tmp[j])!=0){
                    return false;
                }
                m[tmp[j]]=true;
            }
        }
        return true;
    }
    bool isValidColumn(vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            map<char, bool>m;
            for(int j=0; j<9; j++){
                if(board[j][i]!='.' && m.count(board[j][i])!=0){
                    return false;
                }
                m[board[j][i]]=true;
            }
        }
        return true;
    }
    bool isValidBlock(vector<vector<char>>&board){
        for(int i=0; i<3; i++){
            int y=3*i;
            for(int j=0; j<3; j++){
                int x=3*j;
                map<char, bool>m;
                for(int row=0; row<3; row++){
                    for(int col=0; col<3; col++){
                        if(board[y+row][x+col]!='.' && m.count(board[y+row][x+col])!=0){
                            return false;
                        }
                        m[board[y+row][x+col]]=true;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!isValidRow(board)){
            cout << "row" << endl;
        }
        if(!isValidColumn(board)){
            cout << "col" << endl;
        }
        if(!isValidBlock(board)){
            cout << "block" << endl;
        }
        if(!isValidRow(board) || !isValidColumn(board) || !isValidBlock(board)){
            return false;
        }
        return true;
    }
};