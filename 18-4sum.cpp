class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                int k=j+1, l=len-1;
                while(k<l){
                    int sumT = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sumT==target){
                        vector<int>tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        ans.push_back(tmp);
                        k++;
                        l--;
                        while(nums[k]==nums[k-1]){
                            k++;
                        }
                        while(nums[l]==nums[l+1]){
                            l--;
                        }
                    }else if(sumT<target){
                        k++;
                        while(nums[k]==nums[k-1]){
                            k++;
                        }
                    }else{
                        l--;
                        while(nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                }
                while(nums[j+1]==nums[j]){
                   j++;
                }
            }
            while(nums[i+1]==nums[i]){
                i++;
            }          
        }
        return ans;
    }
};