// Time: O(n x 2^n)
// 2^n: total de subconjuntos
// n: para cada subconjunto, custo de copiar para vetor resposta
class Solution {
private:
    void dfs(int i, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        } else if(i >= candidates.size() || target < 0)
            return;

        temp.push_back(candidates[i]);
        dfs(i + 1, target - candidates[i], candidates, temp, ans);

        temp.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1])
            i++;
        dfs(i + 1, target, candidates, temp, ans);
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