// Time: O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n <= 2)
            return 0;
        else{
            int first = 0;
            int second = 0;
            int third;

            for(int i = 2; i <= n; i++){
                third = min(first + cost[i-2], second + cost[i-1]);
                first = second;
                second = third;
            }

            return third;
        }

        
    }
};