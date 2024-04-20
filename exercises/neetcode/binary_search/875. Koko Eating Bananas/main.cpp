// Time: O(log(maxPile)*n)
// Space: O(1)
class Solution {
public:
    /*
        Busca binária convencional: buscamos sobre os possiveis valores dos indices, utilizando como
    critério o valor que dá o indice para aquela velocidade. Calcular o valor envolve o uso do vetor
    dado. Comparamos o valor com o target.
        Busca Koko: buscamos sobre os possiveis valores de velocidade, utilizando como critério
    o valor que dá o tempo para aquela velocidade. Calcular o tempo envolve o uso do vetor dado.
    Comparamos o valor do tempo com o target.
    */
    int minEatingSpeed(vector<int>& piles, int h) {
        // Encontramos a maior velocidade possivel
        int maxPile = 0;
        for(auto pile: piles)        
            maxPile = max(pile, maxPile);

        // Busca binária sobre os valores da velocidade
        int l = 1, r = maxPile, ans = maxPile;
        while (l <= r){
            // Velocidade média
            int mid = (l+r)/2;
            // Calcula o tempo para checar se é uma boa velocidade
            int time = 0;
            for(auto pile : piles)
                time += ceil( (double) pile/mid);
            // Restringe o valor que a velocidade pode assumir.
            if(time <= h){
                r = mid -1;
                ans = mid;
            }
            else if(time > h)
                l = mid + 1;
        }

        return ans;
    }
};
