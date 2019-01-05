class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        map<int, int> m;
        vector<int> validCoins;
        for(int i=0; i<coins.size(); i++){
            if(coins[i]<=amount){
                m[coins[i]] = 1;
                validCoins.push_back(coins[i]);
            }
        }
        vector<int> tmp;
        tmp.assign(validCoins.begin(), validCoins.end());
        bool flag=false;
        while(m.count(amount)==0 && !flag){
            flag=true;
            vector<int> newTmp;
            for(int i=0; i<tmp.size(); i++){
                int tmpPos=tmp[i];
                for(int j=0; j<validCoins.size(); j++){
                    int coinsPos=validCoins[j];
                    if(coinsPos+tmpPos<=amount){
                        flag=false;
                        if(m.count(coinsPos+tmpPos)==0){
                            m[coinsPos+tmpPos] = m[coinsPos]+m[tmpPos];
                            newTmp.push_back(coinsPos+tmpPos);
                        }else if(m[coinsPos]+m[tmpPos]<m[coinsPos+tmpPos]){
                            m[coinsPos+tmpPos] = m[coinsPos]+m[tmpPos];
                            newTmp.push_back(coinsPos+tmpPos);
                        }
                    }       
                }
            }
            tmp = newTmp;
        }
        if(m.count(amount)==0){
            return -1;
        }else{
            return m[amount];
        }
    }
};