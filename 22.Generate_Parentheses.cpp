//I don't know how to deal with the problem
//This is the code after I read the Solution!!!
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";

        addCharacter(result, str, n, n);

        return result;

    }

    void addCharacter(vector<string> &result, string &str, int left, int right)
    {
        if(left > right || left < 0)
            return;
        else if(left == 0 && right == 0)
        {
            result.push_back(str);
            return;
        }

        //处理左括号加1的情况
        str.push_back('(');
        addCharacter(result, str, left - 1, right);
        str.pop_back();

        //处理右括号加1的情况
        str.push_back(')');
        addCharacter(result, str, left, right - 1);
        str.pop_back();

        return;
    }
};
