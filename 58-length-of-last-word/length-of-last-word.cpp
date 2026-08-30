class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        
        // Remove trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        int count = 0;
        
        // Count last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        
        return count;
    }
};