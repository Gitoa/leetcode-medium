class Solution {
private:
    bool isMin = false;
    int minNum;
public:
    void DFS(int row, int col, int depth, int total, vector<vector<int>>& triangle){
        if(col+1 == depth){
            if(isMin){
                minNum = minNum<total?minNum:total;
            }else{
                minNum = total;
                isMin=true;
            }
        }else{
            DFS(row, col+1, depth, total+triangle[col+1][row], triangle);
            DFS(row+1, col+1, depth, total+triangle[col+1][row+1], triangle);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> ans;
        ans.push_back(triangle[0]);
        vector<int> tmp;
        tmp.assign(triangle[0].begin(), triangle[0].end());
        for(int i=1; i<triangle.size(); i++){
            tmp.clear();
            int len = triangle[i].size();
            tmp.push_back(ans[i-1][0]+triangle[i][0]);
            for(int j=1; j<triangle[i].size()-1; j++){
                int tmpNum = ans[i-1][j-1]>ans[i-1][j]?ans[i-1][j]:ans[i-1][j-1];
                tmp.push_back(tmpNum + triangle[i][j]);
            }
            tmp.push_back(ans[i-1][len-2]+triangle[i][len-1]);
            ans.push_back(tmp);
        }
        int ansNum = tmp[0];
        for(int i=0; i<tmp.size(); i++){
            if(ansNum > tmp[i]){
                ansNum = tmp[i];
            }
        }
        return ansNum;
    }
};