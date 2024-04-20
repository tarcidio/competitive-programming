class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            Definições:
            - Barras do histograma: são as barras do histograma que tem as alturas dadas no exercício
            - Retângulo extendido de uma barra: é o maior retângulo na qual aquela barra pertence
            ao se combinar com outras barras
        */
        /*
            Retângulo extendido de uma barra pode ser visto como sendo gerado a partir da barra
        mais uma extensão em barras adjacentes que sejam maiores ou igual a barra original 
        tomada como base. 
            Desta maneira, o algoritmo se baseia em percorrer o vetor de alturas e, para cada altura,
        se perguntar se a altura a seguir é maior que a atual. Se for menor, quer dizer que
        a barra atual não irá conseguir fazer um retângulo extendido com a barra a direita. Neste caso,
        calculamos o retângulo extendido da barra atual considerando apenas as barras que já foram
        analisadas.
            Se for maior, quer dizer que podemos fazer um retângulo extendido utilizando pelo menos 
        a barra a direita. Assim, devemos calcular até que ponto vai essa extensão e, para
        isso, devemos voltar mais tarde para retângulo para calcular a maior da sua extensão. Neste 
        caso, não fazemos nenhum calculo e avançamos mais uma posição na qual fazemos a mesma pergunta
        de antes. Esse momento que há uma sequência de barras uma maior que a outra chamamos de combo.
        */
        
        int n = heights.size();
        stack<pair<int,int>> combo;
        int ans = 0;
       
        // Primeira parte: calculando os retângulos extendidos
        for(int i = 0; i < n; i ++){
            // Onde começa o retângulo extendido desta barra
            // A principio, exatamente a onde a barra começa
            int start = i;

            // Caso o combo seja quebrado, temos que calcular os retângulos das barras anteriores
            // Enquanto a barra atual for menor que todas as anteriores na stack, vai calculando
            // os retângulos extendidos
            while(!combo.empty() && heights[i] < combo.top().first){
                start = combo.top().second;
                int height = combo.top().first;
                combo.pop();

                int end = i;
                int width = end - start;
                int newArea = height * width;

                ans = max(ans, newArea);
            }

            combo.push(make_pair(heights[i], start));
        }

        // Segunda parte: calculando retângulos extendidos faltantes
        /*
            As barras que sobraram e que tiveram seus retângulos calculados tem duas propriedades:
            1. Estão em ordem decrescente na pilha. Caso contrário, haveria uma menor na frente
            de uma maior. Mas como pode haver uma menor na frente de uma maior e não ter sido
            executado o algoritmo de quebra de combo?
            2. Tem o retângulo extendido até a última barra. Se não fosse isso,
            deveria haver pelo menos uma barra menor que alguma delas em sua frente para quebrar
            o combo. Porém, se o combo fosse quebrado, elas não estariam na pilha da segunda parte
        */
        // Desta maneira, basta aplicar o algoritmo considerando que todos os retângulos faltante
        // tem sua extensão até o último indice

        while(!combo.empty()){
            int start = combo.top().second;
            int height = combo.top().first;
            combo.pop();

            int end = n;
            int width = end - start;
            int newArea = height * width;

            ans = max(ans, newArea);
        }

        return ans;
    }
};
