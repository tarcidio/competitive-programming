class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0' )
            return 0;

        int n = s.size();
        int last = 1, penult = 1, cur, two_digits;    

        for(int i = 1; i < n; i++){
            cur = 0;

             // Consider only current digit 
            if(s[i] != '0')
                cur += last;

            // Consider current digit and the previous one
            two_digits = (s[i- 1] - '0')*10 + (s[i] - '0');
            if(two_digits <= 26 && two_digits >= 1)
                cur += penult;
            
            penult = last;
            last = cur;
        }

        return cur;
    }
};