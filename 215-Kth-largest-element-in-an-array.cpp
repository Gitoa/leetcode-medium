class Solution {
public:
    int partition(int left, int right, vector<int> &nums){
        int num = nums[left];
        while(left<right){
            while(left<right && nums[right]<=num){
                right --;
            }
            nums[left] = nums[right];
            while(left<right && nums[left]>=num){
                left ++;
            }
            nums[right] = nums[left];
        }
        nums[left] = num;
        return left;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        int ans = -1;
        while(ans!=k-1){
            if(ans<k-1){
                left = ans+1;
            }else{
                right = ans-1;
            }
            ans = partition(left, right, nums);
        }
        return nums[k-1];
    }
};