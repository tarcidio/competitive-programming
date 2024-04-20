// Time: O(logn + logm)
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get number of rows
        int r = matrix.size() - 1;
        int l = 0;
        int mid;

        // Find row
        while(l <= r){
            mid = (l + r)/2;
            if(matrix[mid][0] < target)
                l = mid + 1;
            else if (matrix[mid][0] > target)
                r = mid - 1;
            else
                return true;
        }

        int row = mid;
        r = matrix[row].size() - 1;
        l = 0;
        while(l <= r){
            mid = (l + r)/2;
            if(matrix[row][mid] < target)
                l = mid + 1;
            else if (matrix[row][mid] > target)
                r = mid - 1;
            else
                return true;
        }

        return false;
    }
};
