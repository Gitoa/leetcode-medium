class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(r>l+1){
            mid = (l+r)/2;
            if(nums[mid]>nums[l]){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(nums[r]<nums[l]){
            return min(nums[r], *(nums.end()-1));
        }else{
            return nums[0];
        }
    }
};