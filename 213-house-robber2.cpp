class Solution {
public:
    int robBad(vector<int>& nums){
        int len = nums.size();
        vector<int> MaxNum(len, 0);
        MaxNum[0] = nums[0];
        MaxNum[1] = max(nums[0], nums[1]);
        int ans = MaxNum[1];
        for(int i=2; i<len; i++){
            MaxNum[i] = max(MaxNum[i-2] + nums[i], MaxNum[i-1]);
            ans = max(ans, MaxNum[i]);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==0){
            return 0;
        }
        if(len==1){
            return nums[0];
        }else if(len==2){
            return max(nums[0], nums[1]);
        }else{
            vector<int> left, right;
            left.assign(nums.begin(), nums.end()-1);
            right.assign(nums.begin()+1, nums.end());
            return max(robBad(left), robBad(right));
        }
    }
};