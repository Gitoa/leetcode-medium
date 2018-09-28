class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    map<int, bool>m;
public:
    void permuDFS(int k, int len, vector<int>nums){
        if(k==len){
            ans.push_back(tmp);
        }else{
            for(int i=0; i<len; i++){
                if(m.count(i)==0){
                    if((i>0&&nums[i]==nums[i-1])&&m.count(i-1)==0){
                        continue;
                    }
                    tmp.push_back(nums[i]);
                    m[i]=true;
                    permuDFS(k+1, len, nums);
                    tmp.erase(tmp.end()-1);
                    m.erase(m.find(i));
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permuDFS(0, nums.size(), nums);
        return ans;
    }
};