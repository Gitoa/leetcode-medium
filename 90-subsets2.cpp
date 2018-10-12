class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void addSubset(vector<int>& nums, int pos, int len, vector<bool>flag){
        ans.push_back(tmp);
        for(int i=pos; i<len; i++){
            if(i==0){
                tmp.push_back(nums[i]);
                flag[i]=true;
                addSubset(nums, i+1, len, flag);
                tmp.erase(tmp.end()-1);
                flag[i]=false;
            }else{
                if(nums[i]!=nums[i-1] || flag[i-1]){
                    tmp.push_back(nums[i]);
                    flag[i]=true;
                    addSubset(nums, i+1, len, flag);
                    tmp.erase(tmp.end()-1);
                    flag[i]=false;
                }
            }
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<bool>flag(len ,false);
        addSubset(nums, 0, len, flag);
        return ans;
    }
};