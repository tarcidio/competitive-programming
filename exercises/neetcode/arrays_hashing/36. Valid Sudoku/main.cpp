// Space: O(N^2)
// Time: O(N^2)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector< unordered_map<int, bool> >  rows (9);
        vector< unordered_map<int, bool> >  cols(9);
        vector< unordered_map<int, bool> >  boxs(9);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                /*Normal linear matrix: i*(size) + j */]
                /*i = row_sudoku//3 */
                /*j = col_sudoku//3 */
                int pos_box = int(i/3)*3 + int(j/3);
                if (board[i][j] == '.')
                    continue;
                else if( rows[i].find(board[i][j]) != rows[i].end() ||
                    cols[j].find(board[i][j]) != cols[j].end() ||
                    boxs[pos_box].find(board[i][j]) != boxs[pos_box].end()
                ) 
                    return false;
                rows[i][board[i][j]] = true;
                cols[j][board[i][j]] = true;
                boxs[pos_box][board[i][j]] = true;
            }
        }

        return true;
    }
};
