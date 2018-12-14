class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> tmpPath, int pos, int num, int sum, int targetSum, int targetNum){
        vector<int> path;
        path.assign(tmpPath.begin(), tmpPath.end());
        if(num == targetNum){
            if(sum == targetSum){
                ans.push_back(path);
            }
        }else{
            if(sum >= targetSum){
                return;
            }else{
                for(int i=pos+1; i<=10-(targetNum-num); i++){
                    path.push_back(i);
                    dfs(path, i, num+1, sum+i, targetSum, targetNum);
                    path.erase(path.end()-1);
                }      
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(path, 0, 0, 0, n, k);
        return ans;
    }
};