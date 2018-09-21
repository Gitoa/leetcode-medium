class Solution {
public:
    void binarySearch(int left, int right, int target, int &pos, vector<int>& nums){
        if(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                pos = mid;
            }else if(nums[mid]<target){
                binarySearch(mid+1, right, target, pos, nums);
            }else{
                binarySearch(left, mid-1, target, pos, nums);
            }
        }
    }
    void unorderSearch(int left, int right, int target, int &pos, vector<int>& nums){
        if(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                pos=mid;
            }else{
                if(nums[mid]>nums[left]){
                    binarySearch(left, mid-1, target, pos, nums);
                    unorderSearch(mid+1, right, target, pos, nums);
                }else{
                    binarySearch(mid+1, right, target, pos, nums);
                    unorderSearch(left, mid-1, target, pos, nums);
                }
            }
        }
    }
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int pos=-1;
        unorderSearch(left, right, target, pos, nums);
        return pos;
    }
};