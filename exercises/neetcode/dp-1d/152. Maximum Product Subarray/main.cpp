// Time: O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1, ans = nums[0], updateCurMax, updateCurMin, n;
        for(int i = 0; i < nums.size(); i++){
            n = nums[i];

            // Use to consider a even number of negativa numbers
            updateCurMax = curMax * n;
            updateCurMin = curMin * n;

            // max(n, ...) and min(n, ...): consider the possibilite like [-1,100]
            curMax = max(n, max(updateCurMax, updateCurMin));
            curMin = min(n, min(updateCurMax, updateCurMin));

            ans = max(ans, curMax);
        }
        return ans;
    }
};