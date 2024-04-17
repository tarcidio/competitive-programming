// Time: O(N*max(biggest(str),26))
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //unordered_map< vector<int>, vector<string> > stored;
        unordered_map<string, vector<string> > stored;

        for(auto str: strs){
            //Calculate vector alphabet
            vector<int> alpha(26, 0);
            for(auto letter : str)
                alpha[letter - 'a']++;

            // Convert alpha to a string
            string str_alpha;
            for(auto it: alpha)
                str_alpha += to_string(it);
            
            // Put in a map
            stored[str_alpha].push_back(str);
        }

        
        vector<vector<string>> ans;
        for(auto it : stored)
            ans.push_back(it.second);

        return ans;
    }
};

