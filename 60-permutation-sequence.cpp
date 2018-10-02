class Solution {
private:
    bool exitFLAG=false;
    string ans;
    string returnAns;
    int num=0;
public:
    void permutationDFS(int depth, int n, int k,  vector<bool>vis){
        if(exitFLAG){
            return;
        }
        if(depth==n){
            num++;
            if(num==k){
                returnAns=ans;
                exitFLAG=true;
            }
            return;
        }
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vis[i]=true;
                ans.push_back('0'+i);
                permutationDFS(depth+1, n, k, vis);
                ans.erase(ans.end()-1);
                vis[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<bool>vis(n+1, false);
        permutationDFS(0, n, k, vis);
        return returnAns;
    }
};