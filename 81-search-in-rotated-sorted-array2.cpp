class Solution {
private:
    bool ans=false;
public:
    void binarySearchSorted(int left, int right, vector<int>& nums, int target){
        if(left<=right && !ans){    
            int mid = (left+right)/2;
            if(nums[mid] == target){
                ans = true;;
            }else if(nums[mid] < target){
                binarySearchSorted(mid+1, right, nums, target);
            }else{
                binarySearchSorted(left, mid-1, nums, target);
            }
        }
    }
    void binarySearchUnsorted(int left, int right, vector<int>& nums, int target){
        if(left<=right && !ans){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                ans=true;
                return;
            }
            if(nums[left] < nums[mid]){
                binarySearchSorted(left, mid-1, nums, target);
            }else{
                binarySearchUnsorted(left, mid-1, nums, target);
            }
            if(nums[mid] < nums[right]){
                binarySearchSorted(mid+1, right, nums, target);
            }else{
                binarySearchUnsorted(mid+1, right, nums, target);
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        binarySearchUnsorted(0, nums.size()-1, nums, target);
        return ans;
    }
};