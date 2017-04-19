//After read the solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};

        vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",  "tuv", "wxyz"};
        vector<string> result = {""}, resultTmp;

        int num;
        for(int i = 0;i < digits.size();i++)
        {
            num = digits[i] - '0';
            for(int j = 0;j < vec[num].size();j++)
               for(int z = 0;z < result.size();z++)
                    resultTmp.push_back(result[z] + vec[num][j]);
            result.swap(resultTmp);
            resultTmp = {};
        }


        return result;
    }
};
