// Time: O(amount*len(coins))
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    // If there aren't, dp[ i - coin[j] ] will return amount + 1 value
                    dp[i] = min(dp[i], 1 + dp[ i - coins[j] ]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};