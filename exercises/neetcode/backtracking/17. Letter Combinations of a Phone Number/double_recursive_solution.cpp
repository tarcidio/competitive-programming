// NAO TERMINADO
class Solution {
    void dfs(unordered_map <char, string> translate, string digits, string& temp, vector<string> &ans, int curr){
        if(curr == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        // Se vai usar esse digito
        temp.push_back(translate[indexDigits][indexTranslate]);
        dfs(indexDigits + 1, 0);

        temp.pop_back();
        // Se nao, use o proximo
        dfs(indexDigits, indexTranslate + 1);

        ...
        
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};

        unordered_map <char, string> translate;
        translate['2'] = {"abc"};
        translate['3'] = {"def"};
        translate['4'] = {"ghi"};
        translate['5'] = {"jkl"};
        translate['6'] = {"mno"};
        translate['7'] = {"pqrs"};
        translate['8'] = {"tuv"};
        translate['9'] = {"wxyz"};
        
        string temp = "";
        vector<string> ans;
        dfs(translate, digits, temp, ans, 0);

        return ans; 
    }
};