class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n==0){
            ans.push_back(0);
            return ans;
        }
        int len = pow(2, n-1);
        for(int i=0; i<len; i++){
            ans.push_back(i);
        }
        vector<int> right = ans;
        reverse(right.begin(), right.end());
        for(int i=0; i<len; i++){
            right[i] += len;
        }
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};