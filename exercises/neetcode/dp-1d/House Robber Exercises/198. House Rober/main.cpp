class Solution {
public:
    int rob(vector<int>& nums) {
        int last = 0, penult = 0, cur;

        for(int i = 0 ; i < nums.size(); i++){
            cur = max(last, penult + nums[i]);
            penult = last;
            last = cur;
        }

        return cur;
    }
};