class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        //只有一列的情况
        if(s.size() <= numRows || numRows == 1)
            return s;

        int i = 0, j = 0, z = 0;
        //第一行
        for(j = 0; i + j *(numRows * 2 - 2) < s.size(); j++)
            result.push_back(s[i + j *(numRows * 2 - 2)]);

        //第二到第numRows - 1行
        for(i = 1;i < numRows - 1;i++)
        {
            int start_set;
            for(start_set = i; start_set < s.size(); start_set = (start_set + numRows * 2 - 2))
            {
                result.push_back(s[start_set]);
                if(start_set + (numRows - 1 - i) * 2 >= s.size())
                    break;
                result.push_back(s[start_set + (numRows - 1 - i) * 2]);
            }
        }

        //最后一行
        i = numRows - 1;
        for(j = 0; i + j *(numRows * 2 - 2) < s.size(); j++)
            result.push_back(s[i + j *(numRows * 2 - 2)]);

        return result;

    }
};
