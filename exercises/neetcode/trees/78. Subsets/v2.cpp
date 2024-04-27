class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numSolutions = pow(2, nums.size());
        vector<int> temp;
        vector<vector<int>> ans;

        for(int i = 0; i < numSolutions; i++){
            for(int j = 0; j < nums.size(); j++){
                if((i >> j) & 1)
                    temp.push_back(nums[j]);
            }

            ans.push_back(temp);
            temp.clear();
        }

        return ans;        
    }
};
