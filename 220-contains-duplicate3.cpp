//超时代码
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool ans = false;
        int len = nums.size();
        if(len<2){
            return ans;
        }
        if(len<=k+1){
            sort(nums.begin(), nums.end());
            for(int i=1; i<len; i++){
                if((nums[i] - nums[i-1] <= t) && (nums[i] - nums[i-1] >= 0)){
                    ans = true;
                    break;
                }
            }
            return ans;
        }
        vector<int>::iterator left, right;
        left = nums.begin();
        right = left + k + 1;
        do{
            right++;
            tmp.assign(left, right);
            sort(tmp.begin(), tmp.end());
            for(int i=1; i<tmp.size(); i++){
                if(tmp[i] - tmp[i-1] <= t){
                    ans = true;
                    break;
                }
            }
            if(ans){
                break;
            }
            left ++;
        }while(right!=nums.end());
        return ans;
    }
};

//标准答案
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2){
            return false;
        }
        multiset<long long> st;
        for(int i=0; i<nums.size(); i++){
            if(i>k){
                st.erase(st.find(nums[i-k-1]));
            }
            auto it = st.lower_bound((long long)nums[i]-t);
            if(it!=st.end() && abs(*it-nums[i])<=t){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};