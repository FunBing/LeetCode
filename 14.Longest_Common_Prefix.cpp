//This is the code after I read the solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int pos = 0, i;

        for(pos = 0; strs.size() > 0 && strs[0].size() > 0; prefix += strs[0][pos], pos++)
        {
            for(i = 0;i < strs.size();i++)
            {
                if(pos >= strs[i].size() || strs[0][pos] != strs[i][pos])
                    return prefix;
            }
        }

        return prefix;
    }
};
