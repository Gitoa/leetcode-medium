class Solution {
private:
    bool exitFLAG=false;
public:
    void jumpDFS(vector<int>&nums, bool &flag, int pos, int end, vector<bool>&vis){
        if(exitFLAG){
            return;
        }
        if(pos<end){
            int step=nums[pos];
            while(step){
                if(!vis[pos+step]){
                    vis[pos+step]=true;
                    jumpDFS(nums, flag, pos+step, end, vis);
                }
                step--;
            }
        }else{
            flag=true;
            exitFLAG=true;
            return;
        }
    }
    bool canJump(vector<int>& nums) {
        bool ans=false;
        vector<bool> vis(nums.size(), false);
        jumpDFS(nums, ans, 0, nums.size()-1, vis);
        return ans;
    }
};