//Time: O(N)
//Space: O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expression;

        for(auto token: tokens){
            // If the first char is digit = number
            // If the first char is '-', but second is digit = number
            if(token.size() > 1 || isdigit(token[0])){
                expression.push(stoi(token));
                continue;
            }
            
            int first = expression.top();
            expression.pop();
            int second = expression.top();
            expression.pop();
            int res = 0;
            if(token == "+")
                res = second + first;
            else if(token == "-")
                res = second - first;
            else if(token == "*")
                res = second * first;
            else
                res = second / first;
            expression.push(res);
        }

        return expression.top();
    }
};
