
// Time: O(n!)
    // Para primeira linha tnmos n possibiildades, para segunda temos n-1, etc.
class Solution {
private:
    // Position that already attacked
    unordered_set<int> cols;
    unordered_set<int> negDiag;
    unordered_set<int> posDiag;
    
    void backtracking(int row, int n, vector<string> &board, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(
                cols.count(col) ||
                negDiag.count(row - col) ||
                posDiag.count(row + col)
            )
                continue;
            
            // Put a queen in board[row][col]
            board[row][col] = 'Q';
            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);

            // Find solutions in others row
            backtracking(row + 1, n, board, ans);

            // Remova a queen in board[row][col] and put in other position
            board[row][col] = '.';
            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board (n, string(n,'.'));
        backtracking(0, n, board, ans);

        return ans;
    }
};