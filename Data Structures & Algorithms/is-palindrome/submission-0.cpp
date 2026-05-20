class Solution {
public:
    bool isPalindrome(string s) {
        // You don't actually need the erase(remove) line now! 
        // The while loop handles spaces and punctuation for you.
        
        int i = 0;
        int backwards = s.size() - 1;

        while (i < backwards) {
            // 1. Advance 'i' until it hits an alphanumeric char
            if (!isalnum(s[i])) {
                i++;
            } 
            // 2. Retreat 'backwards' until it hits an alphanumeric char
            else if (!isalnum(s[backwards])) {
                backwards--;
            } 
            // 3. Compare ONLY when both are valid
            else {
                if (tolower(s[i]) != tolower(s[backwards])) {
                    return false;
                }
                // Move both inward to continue the check
                i++;
                backwards--;
            }
        }
        return true;
    }
};