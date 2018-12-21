class Solution {
public:
    
    int numSquares(int n) {
        vector<int> num(n+1, 0);
        for(int i=0; i<num.size(); i++) num[i] = i;
        for(int i=2; i<num.size(); i++){
            for(int j=1; j*j<=i; j++){
                num[i] = min(num[i],num[i-j*j]+1);
            }
        }
        return num[n];
    }
};