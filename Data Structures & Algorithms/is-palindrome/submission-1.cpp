class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        
        int backwards = s.size()-1;
        int i = 0;

        while (i < backwards) {
            if (!isalnum(s[i])){
                ++i;
            } else if (!isalnum(s[backwards])){
                --backwards; 
            } else {
                if (tolower(s[i]) != tolower(s[backwards])){
                 return false;
                } 
                ++i;
                --backwards;
            }
        }
        return true;
    }
};
