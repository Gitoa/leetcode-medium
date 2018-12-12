class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = 0xfffffff;
        int sum = 0;
        int left = 0, right = 0;
        int len = nums.size();
        while(right<len){
            while(sum<s && right<len){
                sum += nums[right];
                right ++;
            }
            while(sum>=s && left<=right){
                ans = min(ans, right-left);
                sum -= nums[left];
                left ++;
            }
        }
        ans = ans==0xfffffff?0:ans;
        return ans;
    }
};