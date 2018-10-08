class Solution {
private:
    vector<vector<int>> ans;
public:
    void combineAns(int begin, int n, int depth, int k, vector<int>tmp){
        if(depth==k){
            ans.push_back(tmp);
            return;
        }
        for(int i=begin; i<=n; i++){
            tmp.push_back(i);
            combineAns(i+1, n, depth+1, k, tmp);
            tmp.erase(tmp.end()-1);
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        combineAns(1, n, 0, k, tmp);
        return ans;
    }
};