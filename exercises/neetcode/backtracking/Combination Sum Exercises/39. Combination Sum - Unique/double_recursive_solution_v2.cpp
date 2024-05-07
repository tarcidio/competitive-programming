class Solution {
private:
    void dfs(int i, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(i >= candidates.size() || target < 0)
            return;
        else if(!target){
            ans.push_back(temp);
            return;
        }
        // If consider this value, consider a repetition
        temp.push_back(candidates[i]);
        dfs(i, target - candidates[i], candidates, temp, ans);
        // If don't, consider the next value
        temp.pop_back(); 
        dfs(i + 1, target, candidates, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0, target, candidates, temp, ans);

        return ans;        
    }
};
