//Time: O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreqLetter = 0;
        vector<int> countLetter(26,0);
        int l = 0;
        int rangeMax, curRange;

        for(int r = 0; r < s.size(); r++){
            countLetter[s[r] - 'A']++;
            maxFreqLetter = max(maxFreqLetter, countLetter[s[r] - 'A']);

            curRange = r - l + 1;
            // Always find a bigger sequence of equal letter, we can considerar a 
            // bigger maximum range 
            rangeMax = k + maxFreqLetter;

            if(curRange > rangeMax){
                countLetter[s[l] - 'A']--;
                l++;
            }
        }

        return rangeMax;
    }
};
