// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Compare left and right in the same time
        while(left < right){
            // Find the next valid left character
            while(!isalnum(s[left]) && left < right)
                left++;

            // Find the next valid right character
            while(!isalnum(s[right]) && left < right)
                right--;

            // Check
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            
            // Increment
            left++;
            right--;
        }

        return true;
    }
};
