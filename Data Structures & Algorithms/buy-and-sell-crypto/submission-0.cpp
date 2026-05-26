class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //cant sort
        //need to see if there are lower prices and higher prices


        int min = prices[0];
        int maxprofit = 0;
        int currprofit;
        for (int i = 0; i < prices.size(); ++i){
            if (prices[i] < min){
                min = prices[i];
            } else {
                currprofit = prices[i] - min;
                if (currprofit > maxprofit){
                    maxprofit = currprofit;
                }
            }
        }
        return maxprofit;
    }
};
