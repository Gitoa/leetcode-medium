class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        set<int> ansSet;
        vector<int> ans;
        for(int i=0, j=len/3; j<len; j++){
            if(nums[j] == nums[i]){
                ansSet.insert(nums[i]);
                i = j + 1;
                j = i + len/3 - 1;
            }else{
                i++;
            }
        }
        for(set<int>::iterator iter=ansSet.begin(); iter!=ansSet.end(); iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};

//正确解法

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0, b=0, ca=0, cb=0;
        for(int i=0; i<nums.size(); i++){
            int tmp = nums[i];
            if(tmp == a){
                ca++;
            }else if(tmp == b){
                cb++;
            }else if(ca == 0){
                a = tmp;
                ca = 1;
            }else if(cb == 0){
                b = tmp;
                cb = 1;
            }else{
                ca--;
                cb--;
            }
        }
        ca = 0;
        cb = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == a){
                ca ++;
            }
            else if(nums[i] == b){
                cb ++;
            }
        }
        vector<int> ans;
        if(ca>nums.size()/3){
            ans.push_back(a);
        }
        if(cb>nums.size()/3){
            ans.push_back(b);
        }
        return ans;
    }
};