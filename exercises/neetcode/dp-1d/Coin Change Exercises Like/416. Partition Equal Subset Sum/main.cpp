class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Build target
        int target = 0;
        for(auto num: nums)
            target += num;
        if(target % 2)
            return false;
        target /= 2;

        // Build dp
        // dp[i] = true: it is possible to produce a set of numbers whose sum is i
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        // Traverse nums
        for(auto num: nums)
            // Traverse dp right->left
            for(int j = target; j >= num; j--)
                // For each element of dp, check if it is possible
                // to construct the target that dp refers to
                // with this new number from nums
                dp[j] = dp[j] || dp[j - num];
                // The idea here is that for each num, this algorithm "uses"
                // it to set true all those targets equal to it
                // and those equal to other sums minus this num
        
        return dp[target];
    }
};