// Time: O(n)
class Solution {
private:
    int rouber(int start, int end, vector<int>& nums){
        int last = 0, penult = 0, cur;

        for(int i = start; i < end; i++){
            cur = max(last, penult + nums[i]);
            penult = last;
            last = cur;
        }

        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(rouber(0, n-1, nums), rouber(1, n, nums));
    }
};