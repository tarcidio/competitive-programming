//Time: O(N)
//Space: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        // Create prefix
        int prefix = 1;
        for(int i = 0; i < nums.size(); i ++){
            ans[i] *= prefix;
            prefix *= nums[i];
        }
            
        // Create postfix
        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i --){
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};

/*
Input: nums = [1,2,3,4]
prefix = 1;
ans[0] = 1 * 1
ans[1] = ans[0] * 1 * 1
ans[2] = ans[1] * ans[0] * 1 * 1
ans[i] = product of all previous position except it

The same is to postfix

*/
