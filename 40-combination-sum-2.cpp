class Solution {
private:
    vector<vector<int>> res;
    vector<int> method;
public:
    void getCombinationSum(int start, int sum, int target, vector<int> &candidates){
        if(sum>target){
            return;
        }
        else if(sum==target){
            res.push_back(method);
            return;
        }
        else{
            for(int i=start; i<candidates.size(); ++i){
                method.push_back(candidates[i]);
                getCombinationSum(i+1, sum+candidates[i], target, candidates);
                method.pop_back();
                while(i+1<candidates.size()&&candidates[i+1]==candidates[i]){
                    i++;
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum=0;
        getCombinationSum(0, 0, target, candidates);
        return res;
    }
};
