/*Approach 1:
*This problem can be solved using the greedy approach. To maximize the profit we have to minimize the buy cost and we have to sell it at maximum price. *

Follow the steps below to implement the above idea:

1. Declare a buy variable to store the buy cost and max_profit to store the maximum profit.
2. Initialize the buy variable to the first element of the prices array.
3. Iterate over the prices array and check if the current price is minimum or not.
4. If the current price is minimum then buy on this ith day.
5. If the current price is greater than the previous buy then make profit from it and maximize the max_profit.
6. Finally, return the max_profit

Time Complexity: O(N). Where N is the size of prices array. 
Auxiliary Space: O(1). We do not use any extra space. */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices[0], p=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<b){
                b=prices[i];
            }
            else if(prices[i]-b>p){
                p=prices[i]-b;
            }
        }
        return p;
    }
};
