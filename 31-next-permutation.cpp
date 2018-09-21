class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int end = len-1;
        int pos;
        for(pos=end; pos>0; pos--){
            if(nums[pos-1]<nums[pos]){
                break;
            }
        }
        if(pos==0){
            sort(nums.begin(), nums.end());
        }else{
            int pos1=pos-1;
            int pos2=pos;
            for(; pos2<len-1; pos2++){
                if(nums[pos1]>=nums[pos2+1]){
                    break;
                }
            }
            swap(nums[pos1], nums[pos2]);
            reverse(nums.begin()+pos1+1, nums.end());
        }
    }
};