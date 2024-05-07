// Times: O(n*2^n)
    // 2^n: numero de subconjuntos
    // n: para cada subconjunto, custo de copiar para vetor resposta
// Space: O(2^n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> temp;
        vector<vector<int>> ans;
        
        dfs(nums, 0, temp, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            // Consider just the next repetition
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }
};