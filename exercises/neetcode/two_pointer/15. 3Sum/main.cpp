//Time: O(N^2)
//Space: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Idea: fix one number and transform problem in TwoSumOrdered Problem
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        // Improva analysis
        if(nums.size() < 3)
            return {};

        // Fix one number
        for(int i = 0; i < nums.size() - 1; i ++){
            // TwoSumOrdered problem
            int j = i + 1;
            int k = nums.size() - 1;

            // Improva analysis
            if(nums[i] > 0 || nums[k] < 0)
                break;
            
            // If have repition, take care with equals answers
            if(i && nums[i] == nums[i-1])
                continue;
            
            // Loop throgh remaining vector with two points strategy
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                // Put the solution in answer and jump other equals solutions
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(nums[j] == nums[j+1] && j < k)
                        j++;
                    j++;
                    while(nums[k] == nums[k-1] && j < k)
                        k--;
                    k--;  
                }
                // Sum < 0, then right side is bigger
                else if(sum > 0)
                    k--;
                // Sum > 0, then left side is bigger
                else if(sum < 0)
                    j++;
            }
        }
        return ans;
    }
};
