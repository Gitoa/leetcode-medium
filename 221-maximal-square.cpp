class Solution {
public:
    int ans=0;
    bool isOne(int i, int j, int row, int col, vector<vector<char>>& matrix){
        if(i<row && j<col){
            if(matrix[i][j] == '1'){
                return true;
            }
        }
        return false;
    }
    bool isAllOne(int left, int top, int right, int bottom, vector<vector<char>>& matrix){
        for(int i=left; i<right; i++){
            if(matrix[bottom][i] == '0'){
                return false;
            }
        }
        for(int j=top; j<bottom; j++){
            if(matrix[j][right] == '0'){
                return false;
            }
        }
        return true;
    }
    void dfs(int left, int top, int right, int bottom, int row, int col, vector<vector<char>>& matrix){
        ans = max(ans, (right-left)*(right-left));
        if(isOne(bottom, right, row, col, matrix)){
            if(isAllOne(left, top, right, bottom, matrix)){
                dfs(left, top, right+1, bottom+1, row, col, matrix);
            }
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row<1){
            return ans;
        }
        int col = matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]=='1'){
                    dfs(j, i, j+1, i+1, row, col, matrix);
                }
            }
        }
        return ans;
    }
};