//Time and space: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> stored;

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (stored.find(diff) != stored.end()){
                return {stored[diff], i};
            }
            stored[nums[i]] = i;
        }

        return {};
    }
};
