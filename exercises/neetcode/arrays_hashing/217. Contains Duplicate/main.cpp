//Link: https://leetcode.com/problems/contains-duplicate/description/

// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> store;

        for(auto it: nums)
            store.insert(it);

        if(store.size() == nums.size())
            return false;
        else
            return true;

    }
};
