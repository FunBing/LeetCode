//This is the code after I read solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1;
        int length = 0;
        while(s[pos] == ' ' && pos >= 0)
            pos--;
        while(s[pos] != ' ' && pos >= 0)
        {
            pos--;
            length++;
        }

        return length;
    }
};
