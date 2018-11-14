class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int firstLack = 0;
        int longest = -1;
        int len = gas.size();
        for(int i=0; i<len; i++){
            int gasLeft = 0;
            int j;
            for(j=i; j<len; j++){
                gasLeft += gas[j];
                if(gasLeft<cost[j]){
                    break;
                }else{
                    gasLeft -= cost[j];
                }
            }
            if(j==len){
                if(gasLeft>=firstLack){
                    return i;
                }
            }else{
                if(j>longest){
                    int gasLack = cost[j] - gasLeft;
                    firstLack += gasLack;
                }
            }
            longest = max(longest, j);
            i = j;
        }
        return -1;
    }
};