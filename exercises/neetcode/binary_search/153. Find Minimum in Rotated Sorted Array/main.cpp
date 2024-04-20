//Time: O(logn)
//Space: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int curMin = nums[0];

        while(l <= r){
            int mid = (l+r)/2;
            // Solução interessante: manter o num para evitar problemas com extremos
            curMin = min(curMin, nums[mid]);
            
            if(nums[mid] > nums[r])
                l = mid + 1;
            else// Colocar o if aqui pode levar a loop infinito caso se o mid correto
                r = mid - 1;                        
        }

        return curMin;
    }
};
