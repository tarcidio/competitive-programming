// Time: O(n x 2^n)
// 2^n: total de subconjuntos
// n: para cada subconjunto, custo de copiar para vetor resposta
class Solution {
private:
    void dfs(int i, int target, int curSum, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(i >= candidates.size() || curSum > target)
            return;
        else if(curSum == target){
            ans.push_back(temp);
            return;
        }
        // If consider this value, consider a repetition
        temp.push_back(candidates[i]);
        dfs(i, target, curSum + candidates[i], candidates, temp, ans);
        // If don't, consider the next value
        temp.pop_back(); 
        dfs(i + 1, target, curSum, candidates, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0, target, 0, candidates, temp, ans);

        return ans;        
    }
};
