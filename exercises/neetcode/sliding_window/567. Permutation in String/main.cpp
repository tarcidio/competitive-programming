class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s1Size > s2Size) {
            return false;
        }
        
        vector<int> count(26);
        for (int i = 0; i < s1Size; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) {
            return true;
        }
        
        for (int i = s1Size; i < s2Size; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - s1Size] - 'a']++;
            if (isPermutation(count)) {
                return true;
            }
        }
        
        return false;
    }
private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
