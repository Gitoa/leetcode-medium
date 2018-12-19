class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int right=1, len=nums.size();
        ans.push_back(1);
        for(int i=0; i<len-1; i++){
            ans.push_back(ans[i] * nums[i]);
        }
        for(int i=len-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};