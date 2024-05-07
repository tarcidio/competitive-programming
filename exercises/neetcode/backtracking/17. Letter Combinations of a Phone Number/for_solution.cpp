//Time: O(n*4^n)
    //n: passar a temp para ans
    //4^n: cada posição do digito gera 4 possibilidades
class Solution {
    void dfs(unordered_map <char, string> translate, string digits, string& temp, vector<string> &ans, int curr){
        if(curr == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0;  j < translate[digits[curr]].size(); j++){
            temp.push_back(translate[digits[curr]][j]);
            dfs(translate, digits, temp, ans, curr + 1);
            temp.pop_back();
        }
        
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