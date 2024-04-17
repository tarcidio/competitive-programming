// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> count;
        for(auto num: nums)
            count[num]++;

        // N + 1 because the biggest frequence is N (that is N + 1 index)
        vector< vector<int> > freq(nums.size() + 1, vector<int>());
        for(auto pair: count)
            freq[pair.second].push_back(pair.first);

        vector<int> ans;
        int count_k = 0;
        for(int i = freq.size() - 1; i > 0; i--){
            for(auto it: freq[i]){
                ans.push_back(it);
                count_k++;
                if(count_k == k)
                    return ans;
            }
        }

        return {};
    }
};
