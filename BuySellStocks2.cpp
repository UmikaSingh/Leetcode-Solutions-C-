class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=-1, sell, profit=0, n=prices.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            if(i<n-1 && buy<0 && prices[i+1]>prices[i]) buy=prices[i];
            else if(buy>=0 && (i==n-1 || prices[i+1]<prices[i] )  ){
                sell=prices[i];
                profit+=sell-buy;
                buy=-1;
                
            }
        }
        return profit;
    }
};
