// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //O(N)
        unordered_set<int> setNums (nums.begin(), nums.end());

        int ans = 1;
        //O(N)
        for(auto num: setNums){
            //O(1): hashing
            if(!setNums.count(num - 1)){
                int newAns = 1;
                //O(N): but, if N, this if won't done again
                while (setNums.count(num + newAns)){
                    newAns++;
                }
                ans = max(ans, newAns);
            }
        }

        return ans;
    }
};
