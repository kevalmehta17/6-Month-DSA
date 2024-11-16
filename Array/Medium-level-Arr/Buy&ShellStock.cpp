//here first we have to find min value to buy a stock then every
// iteration of arr we can minus it from arr[i] to find ourCost and then find
// max from it(Profit),so first value always be min value then after
// every iteration update the min value & every day we have to
// minus from arr[i] then find max in it and return it

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int timeToBuy = prices[0]; //Min value of share
        int profit = 0;
        for(int i = 1;i<n;i++){
            int myCostIfIShell = prices[i]-timeToBuy;
            profit = max(myCostIfIShell,profit);
            timeToBuy = min(prices[i],timeToBuy);
        }
        return profit;
        
    }
};

// gfg Practice code:-

class Solution {
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int>& A, int n) {
        vector<vector<int>> result;
        
        // Loop through the array to find profitable segments
        for (int i = 0; i < n - 1; i++) {
            // If the next day's price is greater than today's, we have a profit opportunity
            if (A[i + 1] > A[i]) {
                result.push_back({i, i + 1});  // Record the buy and sell day indices
            }
        }
        
        // If no profit opportunity is found, return an empty vector
        
        return result;
    }
};