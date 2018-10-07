class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len0=0, len2=0, pos=0, len=nums.size();
        while(nums[pos]==0){
            len0++;
            pos++;
        }
        while(nums[len-len2-1]==2){
            len2++;
        }
        while(pos+len2<len){
            if(nums[pos]==0){
                swap(nums[pos], nums[len0++]);
                pos++;
            }else if(nums[pos]==2){
                swap(nums[pos], nums[len-len2-1]);
                len2++;
            }else{
                pos++;
            }
        }
    }
};