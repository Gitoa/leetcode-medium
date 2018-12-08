class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ans=0;
        int maxPos=0, maxNeg=0;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(num == 0){
                maxPos = 0; 
                maxNeg = 0;
            }else if(num>0){
                maxPos = max(maxPos * num, num);
                maxNeg = maxNeg * num;
            }else{
                int tmp = maxPos;
                maxPos = maxNeg * num;
                maxNeg = min(tmp * num, num);
            }
            ans = max(ans, maxPos);
        }
        return ans;
    }
};