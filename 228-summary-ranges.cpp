class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left=0, right=1;
        vector<string> ans;
        while(right<nums.size()){
            while(right<nums.size() && nums[right-1] == nums[right]-1){
                right++;
            }
            if(right-left==1){
                ans.push_back(to_string(nums[left]));
            }else{
                string str="";
                str += to_string(nums[left]);
                str += "->";
                str += to_string(nums[right-1]);
                ans.push_back(str);
            }
            left = right;
            right = left + 1;
        }
        if(left!=nums.size()){
            ans.push_back(to_string(nums[left]));
        }
        return ans;
    }
};