class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        double carry=x;
        bool flag=true;
        long long tmp=n;
        if(n<0){
            flag=false;
            tmp=-tmp;
        }
        while(tmp){
            if(tmp&1){
                ans *= carry;
            }
            tmp>>=1;
            carry *= carry;
            
        }
        if(flag){
            return ans;
        }
        return 1/ans;
    }
};