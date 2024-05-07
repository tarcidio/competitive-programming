class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 2;
        int third;

        if(n == 1)
            return first;
        else if(n == 2)
            return second;
        
        for(int i = 2;  i < n; i++){
            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }
};