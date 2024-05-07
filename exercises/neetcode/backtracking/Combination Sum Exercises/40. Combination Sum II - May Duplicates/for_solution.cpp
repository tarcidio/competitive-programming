// Time: O(2^n)
class Solution {
private:
    void dfs(int start, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        } else if(target < 0)
            return;
        
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        dfs(0, target, candidates, temp, ans);

        return ans;
    }
};