class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<int>sell(prices.size()+1, 0);
        vector<int>buy(prices.size()+1, 0);
        buy[1]=-prices[0];
        for(int i=2; i<prices.size()+1; i++){
            buy[i] = max(sell[i-2]-prices[i-1], buy[i-1]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);
        }
        return sell[prices.size()];
    }
};