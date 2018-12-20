//递归写法，效率很低，改成非递归写法。

class Solution {
public:
    bool ans=false;
    void searchOne(vector<vector<int>>& matrix, int target, int right, int top){
        if(right==-1 || top==matrix.size()){
            return;
        }
        int i=0, j=0;
        for(i=0; i<right; i++){
            if(matrix[top][i] == target){
                ans = true;
                return;
            }else if(matrix[top][i]>target){
                break;
            }
        }
        if(i>0){
            for(j=top; j<matrix.size(); j++){
                if(matrix[j][i-1] == target){
                    ans = true;
                    return;
                }else if(matrix[j][i-1]>target){
                    break;
                }
            }
        }
        searchOne(matrix, target, i-1, j);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()!=0){
            searchOne(matrix, target, matrix[0].size(), 0);
        }
        return ans;
    }
};


//非递归写法

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int top = 0, right = matrix[0].size()-1;
        while(top<matrix.size() && right>=0){
            if(matrix[top][right] == target) return true;
            else if(matrix[top][right] > target) right--;
            else top++;
        }
        return false;
    }
};