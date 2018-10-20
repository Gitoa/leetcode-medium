class Solution {
public:
    int bstNum(int left, int right){
        int ans=0;
        if(left>=right){
            return 1;
        }else{
            for(int i=left; i<=right; i++){
                ans += bstNum(left, i-1)*bstNum(i+1, right);
            }
        }
        return ans;
    }
    int numTrees(int n) {
        vector<int> ans(n+1, 0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2; i<=n; i++){
            int tmp=0;
            for(int j=0; j<=i; j++){
                tmp += ans[j] * ans[i-j-1];
            }
            ans[i] = tmp;
        }
        return ans[n];
    }
};