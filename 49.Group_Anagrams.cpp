//This is my own code
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> subResult;

        for(auto str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(subResult.find(tmp) == subResult.end())
                subResult[tmp] = {str};
            else
                subResult[tmp].push_back(str);
        }

        vector<vector<string>> result;
        for(auto iter = subResult.begin(); iter != subResult.end(); ++iter)
            result.push_back(iter -> second);

        return result;
    }
};
