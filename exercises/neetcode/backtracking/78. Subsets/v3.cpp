class Solution {
private:
    void dfs(int start, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        
        for(int i = start; i < nums.size(); i++){
             temp.push_back(nums[i]);
            dfs(i+1, nums, temp, ans);
            temp.pop_back(); 
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0, nums, temp, ans);

        return ans;        
    }
};
