// Time: O(n^3)
    //1ª n: loop through left->right
    //2ª n: loop through right->left
    //3ª n: get substr
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create a set to consult
        unordered_set<string> words;
        for(auto word : wordDict){
            words.insert(word);
        }

        // Create dp vector
        int n = s.size();
        //dp[i] = true: indicates it can segmented util s[i- 1]
        vector<bool> dp(n + 1);
        dp[0] = true;

        //mar lugares que posso checar dp[i] = true
        
        // Loop through dp left->right
        for(int i = 1; i < n + 1; i++)
            // Loop through dp right->left by i - 1
            for(int j = i - 1; j >= 0; j--)
                // If true, indicates that the position is the end of a segment
                if(dp[j]){
                    // Check if from there to here it is also a segment
                    string word = s.substr(j, i - j);//s.substr( (j-1) + 1, (i-1)- (j-1+1) + 1)
                    if(words.count(word)){
                        dp[i] = true;
                        break;
                    }
                }
            
        return dp[n];
    }
};