class Solution {
private:
    vector<vector<int>> ans;
public:
    void addSubset(int pos, vector<int>tmp, int len, vector<int>& nums){
        ans.push_back(tmp);
        for(int i=pos; i<len; i++){
            tmp.push_back(nums[i]);
            addSubset(i+1, tmp, len, nums);
            tmp.erase(tmp.end()-1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        addSubset(0, tmp, nums.size(), nums);
        return ans;
    }
};