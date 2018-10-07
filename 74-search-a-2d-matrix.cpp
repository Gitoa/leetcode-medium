class Solution {
private: 
    bool ans=false;
public:
    void binarySearch(int left, int right, vector<vector<int>>& matrix, int target, int row, int col){
        if(left>right){
            return;
        }
        int mid=(left+right)/2;
        if(matrix[mid/col][mid%col]==target){
            ans=true;
            return;
        }
        else if(matrix[mid/col][mid%col]<target){
            binarySearch(mid+1, right, matrix, target, row, col);
        }else{
            binarySearch(left, mid-1, matrix, target, row, col);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row){
            return false;
        }
        int col = matrix[0].size();
        int left=0, right=row*col-1;
        binarySearch(left, right, matrix, target, row, col);
        return ans;
    }
};