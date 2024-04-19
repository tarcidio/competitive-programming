//Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValid(string s) {
        if(!s.size()%2)
            return false;
        
        stack<char> brackets;
        for(auto bracket: s)
            if(bracket == '{') brackets.push('}');
            else if(bracket == '[') brackets.push(']');
            else if(bracket == '(') brackets.push(')');
            else if (brackets.top() == bracket) brackets.pop();
            else return false;

        return true;
    }
};
