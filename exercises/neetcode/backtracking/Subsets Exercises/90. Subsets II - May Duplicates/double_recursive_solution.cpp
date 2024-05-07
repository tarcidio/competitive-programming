// Time: O(n x 2^n)
// 2^n: total de subconjuntos
// n: para cada subconjunto, custo de copiar para vetor resposta
// Space: O(2^n)
class Solution {
private:
    void dfs(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        dfs(i + 1, nums, temp, ans);

        temp.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1])
            i++;
        dfs(i + 1, nums, temp, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(0,nums, temp, ans);
        return ans;
    }
};