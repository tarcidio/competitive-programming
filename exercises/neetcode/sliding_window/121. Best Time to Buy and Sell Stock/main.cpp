// Time: O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lowest = prices[0];
        for(auto price: prices){
            if(lowest > price)
                lowest = price;
            res = max(res, price - lowest);
        }
        return res;

        /*
            O preço de hoje menos o menor preço até agora encontrado é maior que qualquer outra 
        diferença nessa mesma situação em dias anteriores?
        */
    }
};
