//This is the code after I read the solutions
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int i, result = 0;
        for(i = 0;i < s.length() - 1;i++)
        {
            if(T[s[i]] < T[s[i + 1]])
                result -= T[s[i]];
            else
                result += T[s[i]];
        }

        return result + T[s[i]];
    }
};
