// Time: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        //dp[i]: indicates value of LIS util nums[i]
        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};