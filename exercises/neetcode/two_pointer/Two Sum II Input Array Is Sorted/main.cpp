//Time: O(N)
//Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //number
            //1-indexed
            //sorted in non-decreasing
            //ans= [index1 + 1, index2 + 2]
        
        int l = 0;
        int r = numbers.size() - 1;

        while(l < r){
            int sum = numbers[l] + numbers[r];

            if(sum == target)
                return {l + 1, r + 1};
            else if (sum > target)
                r--;
            else if(sum < target)
                l++;
        }

        return {};
    }
};
