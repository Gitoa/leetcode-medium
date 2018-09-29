class Solution {
private:
<<<<<<< HEAD
    set<vector<int>> ret;
public:
    void perm(vector<int> &nums, int k, int m){
        if(k==m-1){
            ret.insert(nums);
        }else{
            for(int i=k; i<m; i++){
                    swap(nums[k], nums[i]);
                    perm(nums, k+1, m);
                    swap(nums[k], nums[i]);
                
=======
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
>>>>>>> 81cacd30f3a4605b5e3bc05bec64c340cc8b81b9
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
<<<<<<< HEAD
        perm(nums, 0, nums.size());
        return vector<vector<int>> (ret.begin(), ret.end());
    }
};
=======
        sort(nums.begin(), nums.end());
        permuDFS(0, nums.size(), nums);
        return ans;
    }
};
>>>>>>> 81cacd30f3a4605b5e3bc05bec64c340cc8b81b9
