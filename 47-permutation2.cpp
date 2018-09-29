class Solution {
private:
    set<vector<int>> ret;
public:
    void perm(vector<int> &nums, int k, int m){
        if(k==m-1){
            ret.insert(nums);
        }else{
            for(int i=k; i<m; i++){
                    swap(nums[k], nums[i]);
                    perm(nums, k+1, m);
                    swap(nums[k], nums[i]);
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm(nums, 0, nums.size());
        return vector<vector<int>> (ret.begin(), ret.end());
    }
};
