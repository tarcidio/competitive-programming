// Time: O(n*n!)
    // n!: número de permutações
    // n: para cada permutação, custo de copiar para vetor resposta
// Space: O(n!)
class Solution {
    void makePermutation(int start, vector<int>& nums, vector<vector<int>>& ans){
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            // Fix one
            swap(nums[start], nums[i]);
            // Calculate permutations permuting remaining elements
            makePermutation(start + 1, nums, ans);
            // Reverte to start new loop
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        makePermutation(0, nums, ans);

        return ans;        
    }
};
