class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i,j,k;
        int minDis = 10000000;
        int close=0;
        vector<int> num(nums);
        sort(num.begin(), num.end());
        int len = num.size();
        for(i=0; i<len; i++){
            j = i + 1;
            k = len - 1;
            while(j < k){
                int ans = num[i]+num[j]+num[k];
                if(ans==target){
                    return ans;
                }else if(ans>target){
                    if(abs(ans-target)<minDis){
                        minDis = abs(ans-target);
                        close = ans;
                    }
                    k--;
                    while(k>-1&&num[k+1]==num[k]){
                        k--;
                    }
                }else{
                    if(abs(ans-target)<minDis){
                        minDis = abs(ans-target);
                        close = ans;
                    }
                    j++;
                    while(j<len&&num[j-1]==num[j]){
                        j++;
                    }
                }
            }
        }
        return close;
        
    }
};