// Time: O(n^2)
class Solution {
    void middleOut(int i, int j, string& s, int& count){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            count++;
        }
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0 ; i < s.size(); i++){
            middleOut(i, i, s, count);
            middleOut(i, i + 1, s, count);
        }
        return count;
    }
};