class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 2147483647;
        int profit = 0;
        for (int n: prices) {
            if (buy > n) {
                buy = n;
                continue ;
            }
            int profitCalc = n - buy;
            if (profitCalc > profit)
                profit = profitCalc;
        }
        return profit;
    }
};
