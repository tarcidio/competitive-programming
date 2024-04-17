// Initial questions:

// Two examples: true and false
// Size of s and t
// Lower ou upppercase?
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        } else{
            int alpha_s[26] = {0};
            int alpha_t[26] = {0};

            for(int i = 0; i < s.size(); i++){
                alpha_s[s[i] - 'a']++;
                alpha_t[t[i] - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                if(alpha_t[i] != alpha_s[i])
                    return false;
            }

            return true;
        }
        
    }
};
