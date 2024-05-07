// Time: O(n^2)
class Solution {
private:
    void middleOut(int i, int j, int& maxLength, int& maxStart, string& s){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }

        // Must be +1 to calculate length because it's index, but i and j need be decremented in -2 
        int newLength = j - i - 1; 
        if(newLength > maxLength){
            maxLength = newLength;
            maxStart = i + 1;
        }
    }
public:
    string longestPalindrome(string s) {
        int maxLength = 0, maxStart = 0;
        for(int i = 0; i < s.size(); i++){
            middleOut(i, i, maxLength, maxStart, s);
            middleOut(i, i + 1, maxLength, maxStart, s);
        }

        return s.substr(maxStart, maxLength);
    }
};