class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> store;
        int l = 0;
        int ans = 0;
        
        for(int r = 0; r < s.size(); r++){
            // Remove lefts chars while don't have repetition
            while(store.count(s[r])){
                store.erase(s[l]);
                l++;
            }

            store.insert(s[r]);
            ans = max(ans, r + 1 - l);
        }

        return ans;
    }
};
