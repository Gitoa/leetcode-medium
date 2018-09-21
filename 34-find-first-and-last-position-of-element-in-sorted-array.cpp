class Solution {
public:
    void binarySearch(int left, int right, int &pos, int target, vector<int>&nums){
        if(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                pos=mid;
            }else if(nums[mid]>target){
                binarySearch(left, mid-1, pos, target, nums);
            }else{
                binarySearch(mid+1, right, pos, target, nums);
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos=-1, left=0, right=nums.size()-1;
        vector<int>ans;
        binarySearch(left, right, pos, target, nums);
        if(pos==-1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int posL = pos, posR = pos;
        while(posL-1>=0 && nums[posL-1]==nums[pos]){
            posL--;
        }
        while(posR+1<=right && nums[posR+1]==nums[pos]){
            posR++;
        }
        ans.push_back(posL);
        ans.push_back(posR);
        return ans;
    }
};