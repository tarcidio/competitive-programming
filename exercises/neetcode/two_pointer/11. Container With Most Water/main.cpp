//Time: O(N)
//Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while(l < r){
            ans = max(ans, (r - l)*min(height[l], height[r]) );
            //The only chance to increase the area is 
            //if the next height is greater than the previous one
            //as we will decrease the length of the area
            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};
