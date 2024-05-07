class Solution {
private:
    void dfs(int start, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }else if(target < 0)
            return;

        for(int i = start; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            // "unlimited number of times": so, don't use i + 1
            dfs(i, target - candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0, target, candidates, temp, ans);

        return ans;        
    }
};