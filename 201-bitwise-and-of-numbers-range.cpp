class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> bitM, bitN;
        while(m!=0){
            bitM.push_back(m%2);
            m /= 2;
        }
        while(n!=0){
            bitN.push_back(n%2);
            n /= 2;
        }
        if(bitM.size()!=bitN.size()){
            return 0;
        }
        int len = bitM.size();
        vector<int> ans;
        int i;
        for(i=len-1; i>=0; i--){
            if(bitM[i]==bitN[i]){
                ans.push_back(bitM[i]);
            }else{
                break;
            }
        }
        while(i>=0){
            ans.push_back(0);
            i--;
        }
        int andAns=0;
        for(i=0; i<ans.size(); i++){
            andAns *= 2;
            andAns += ans[i];
        }
        return andAns;
    }
};

//思路是对的，但是比位操作耗时太多

//Bit Manipulation
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};