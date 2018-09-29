class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                ans[j].push_back(matrix[i][j]);
            }
        }
        matrix=ans;
    }
};




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        for(i=n-1; i>=0; i--){
            int col=n-i-1;
            if(i==n-1){
                for(int j=0; j<n; j++){
                    matrix[j].insert(matrix[j].begin()+col, matrix[i][col]);
                    matrix[i].erase(matrix[i].begin()+col);
                }
            }else{
                for(int j=0; j<n; j++){
                    if(j<i){
                        matrix[j].insert(matrix[j].begin()+col, matrix[i][col]);
                        matrix[i].erase(matrix[i].begin()+col);
                    }else if(j>i){
                        matrix[j].insert(matrix[j].begin()+col,matrix[i][col+1]);
                        matrix[i].erase(matrix[i].begin()+col+1);
                    }
                }
            }
        }
    }
};