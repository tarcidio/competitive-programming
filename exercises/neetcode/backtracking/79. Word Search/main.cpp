// Time: `O(n*m*4^k)`
/*
    O pior caso, o algoritmo pode potencialmente explorar todas as células da matriz para cada caractere da palavra. 
    Se a matriz tem dimensões `n x m` e a palavra tem comprimento `k`, então, em teoria, 
    cada célula pode ser o ponto de partida para a busca da palavra completa. 
    Assim, a complexidade de tempo no pior caso seria `O(n*m*4^k)`, onde `4^k` representa o 
    número máximo de caminhos a serem explorados para cada chamada de DFS (uma vez que há 4 direções 
    possíveis a explorar e a palavra tem comprimento `k`).

    Em algumas anaálises, é possivel considerar o O(n*m*3^k), por que na veerdade teria apenas 3 caminhos já que
    o anterior terá preenchido '#' e não será mais usado.
*/
// Space: O(k)
/**
     O algoritmo utiliza espaço adicional para a pilha de chamadas de recursão, 
     que no máximo será do tamanho da palavra `k` (profundidade máxima da recursão). 
     Além disso, a matriz é modificada durante a execução do algoritmo 
     (os caracteres são temporariamente substituídos por `#`), mas isso é feito in-place, 
     então não requer espaço extra significativo além do espaço já utilizado pela matriz de entrada
*/
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string &word, int n, int m, int index, int i, int j){
        if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] != word[index])
            return false;
        if(index == word.size() - 1)
            return true;

        board[i][j] = '#';

        if(
            dfs(board, word, n, m, index + 1, i + 1, j) ||
            dfs(board, word, n, m, index + 1, i - 1, j) ||
            dfs(board, word, n, m, index + 1, i, j + 1) ||
            dfs(board, word, n, m, index + 1, i, j - 1)
        )
            return true;
        
        board[i][j] = word[index];

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == word[0] && dfs(board,word, n, m, 0, i, j))
                    return true;
            
        return false;
    }
};