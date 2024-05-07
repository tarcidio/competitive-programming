// Time: O(n*2^2n)
class Solution {
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(int start, int end, string& str, vector<string>& temp, vector<vector<string>>& ans){
        if(start == str.size()){
            ans.push_back(temp);
            return;
        }else if(end == str.size())
            return;
        

        if(isPalindrome(str, start, end)){
            temp.push_back( str.substr(start, end - start + 1) );
            dfs(end + 1, end + 1, str, temp, ans);
            temp.pop_back();
        }          
        
        dfs(start, end + 1, str, temp, ans);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        dfs(0, 0, s, temp, ans);

        return ans;
    }
};